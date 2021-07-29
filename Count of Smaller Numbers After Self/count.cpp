class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>> idxVal; // vector of {index, value} pairs from nums
        for (int i=0; i<n; i++) {
            idxVal.push_back({i, nums[i]});
        }
        
        vector<int> ans(n);
        
        mergeSortCount(idxVal, 0, n-1, ans);
        
        return ans;
    }
    
private:
    void mergeSortCount(vector<pair<int, int>>& idxVal, int start, int end, vector<int>& ans) {
        if (start >= end) {
            return;
        }
        
        int mid = start + (end - start) / 2;
        mergeSortCount(idxVal, start, mid, ans);
        mergeSortCount(idxVal, mid+1, end, ans);
        
        int left = start;
        int right = mid + 1;
        int countSmallerRight = 0; // count of elements in right subarray that are smaller than elements in left subarray
        vector<pair<int, int>> merged;
        
        while (left <= mid && right <= end) {
            if (idxVal[left].second > idxVal[right].second) {
                countSmallerRight++;
                
                merged.push_back(idxVal[right]);
                right++;
            } else {
                ans[idxVal[left].first] += countSmallerRight;
                
                merged.push_back(idxVal[left]);
                left++;
            }
        }
        
        while (left <= mid) {
            ans[idxVal[left].first] += countSmallerRight;
            
            merged.push_back(idxVal[left]);
            left++;
        }
        
        while (right <= end) {
            merged.push_back(idxVal[right]);
            right++;
        }
        
        int i = start;
        for (auto p: merged) {
            idxVal[i] = p;
            i++;
        }
    }
};