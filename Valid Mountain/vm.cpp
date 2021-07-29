class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int start = 0;
        int peak = 0;
        int end = arr.size() - 1;
        
        int i = 0;
        while (i < end && arr[i] < arr[i+1]) {
            i++;
        }
        peak = i;
        while (i < end && arr[i] > arr[i+1]) {
            i++;
        }
        
        return (start < peak && peak < end && end == i);
    }
};