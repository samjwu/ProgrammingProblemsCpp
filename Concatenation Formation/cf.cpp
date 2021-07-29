class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, int> pos;
        for (int i = 0; i < pieces.size(); i++) {
            pos[pieces[i][0]] = i+1;
        }
        
        int idx = 0;
        while (idx < arr.size()) {
            int i = pos[arr[idx]];
            int j = 0;
            
            if (i == 0) {
                return false;
            }
            
            while (j < pieces[i-1].size()) {
                if (arr[idx] != pieces[i-1][j]) {
                    return false;
                }
                
                idx++;
                j++;
            }
        }
        
        return true;
    }
};