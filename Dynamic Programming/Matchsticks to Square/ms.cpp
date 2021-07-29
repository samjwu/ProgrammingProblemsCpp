class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        n = matchsticks.size();
        if (n < 4) {
            return false;
        }
        
        int perim = 0;
        for (int stick: matchsticks) {
            perim += stick;
        }
        
        if (perim % 4 != 0) {
            return false;
        }
        
        sidelen = perim / 4;
        vector<int> sides(4, 0);
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        return dfs(matchsticks, 0, sides);
    }
    
private:
    int n;
    int sidelen;
    
    bool dfs(vector<int>& sticks, int i, vector<int>& sides) {
        if (i == n) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        
        for (int j=0; j<4; j++) {
            if (sides[j] + sticks[i] <= sidelen) {
                sides[j] += sticks[i];
                
                if (dfs(sticks, i+1, sides)) {
                    return true;
                }
                
                sides[j] -= sticks[i];
            }
        }
        
        return false;
    }
};