class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        }
        
        int size = heights.size();
        vector<int> left(size);
        vector<int> right(size);
        left[0] = -1;
        right[size-1] = size;
        
        for (int i = 1; i < size; i++) {
            int idx = i-1;
            
            while (idx >= 0 && heights[idx] >= heights[i]) {
                idx = left[idx];
            }
            left[i] = idx;
        }
        
        for (int i = size-2; i >= 0; i--) {
            int idx = i+1;
            
            while (idx < size && heights[idx] >= heights[i]) {
                idx = right[idx];
            }
            right[i] = idx;
        }
        
        int ans = 0;
        for (int i = 0; i < size; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        
        return ans;
    }
};