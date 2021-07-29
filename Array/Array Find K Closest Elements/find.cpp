class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        
        if (n == k) {
            return arr;
        }
        
        int r = binSearch(arr, x, 0, n-1);
        int l = r - 1;
        
        while (k > 0) {
            if (l < 0) {
                ans.push_back(arr[r]);
                r++;
                k--;
                continue;
            } else if (r == n) {
                ans.push_back(arr[l]);
                l--;
                k--;
                continue;
            }
            
            int diffL = abs(arr[l] - x);
            int diffR = abs(arr[r] - x);
            
            if (diffL <= diffR) {
                ans.push_back(arr[l]);
                l--;
            } else {
                ans.push_back(arr[r]);
                r++;
            }
            
            k--;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
private:
    // will return idx where arr[idx] >= target
    int binSearch(vector<int>& arr, int target, int l, int r) {
        int m = l + (r-l)/2;
        
        while (l < r) {
            if (arr[m] == target) {
                return m;
            } else if (arr[m] < target) {
                l = m+1;
            } else {
                r = m;
            }
            
            m = l + (r-l)/2;
        }
        
        return m;
    }
};