class Solution {
public:
    bool jump(vector<int>& arr, int idx, vector<bool>& visited) {
        if (arr[idx] == 0) {
            return true;
        }
        
        if (visited[idx] == true) {
            return false;
        }
        
        visited[idx] = true;
        
        bool ans = false;
        
        if (idx - arr[idx] >= 0) {
            ans = ans || jump(arr, idx - arr[idx], visited);    
        }
        
        if (idx + arr[idx] <= arr.size()-1) {
            ans = ans || jump(arr, idx + arr[idx], visited);
        }
        
        return ans;
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return jump(arr, start, visited);
    }
};