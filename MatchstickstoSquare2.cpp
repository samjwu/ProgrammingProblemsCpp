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
        
        return dfs(matchsticks, (1 << n) - 1, 0);
    }
    
private:
    int n;
    int sidelen;
    map<vector<int>, int> memo;
    
    bool dfs(vector<int>& sticks, int mask, int fullSides) {
        vector<int> memoKey = {mask, fullSides};
        
        int currPerim = 0;
        for (int i=n-1; i>=0; i--) {
            if ((mask & (1 << i)) == 0) {
                currPerim += sticks[n-1-i];
            }
        }
        
        if (currPerim > 0 && currPerim % sidelen == 0) {
            fullSides++;
        }
        
        if (fullSides == 3) {
            return true;
        }
        
        if (memo[memoKey] != 0) {
            return memo[memoKey] == 1;
        }
        
        bool ans = false;
        
        int currSide = currPerim / sidelen;
        int rem = sidelen * (currSide+1) - currPerim;
        
        for (int i=n-1; i>=0; i--) {
            if (sticks[n-1-i] <= rem && (mask & (1 << i)) > 0) {
                if (dfs(sticks, (mask ^ (1 << i)), fullSides)) {
                    ans = true;
                    break;
                }
            }
        }
        
        if (ans == true) {
            memo[memoKey] = 1;
        } else {
            memo[memoKey] = -1;
        }
        return ans;
    }
};