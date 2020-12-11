class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        
        int i = 0;
        while (i < end && arr[i] < arr[i+1]) {
            i++;
        }
        if (i == 0 || i == end) {
            return false;
        }
        while (i < end && arr[i] > arr[i+1]) {
            i++;
        }
        
        return i == end;
    }
};