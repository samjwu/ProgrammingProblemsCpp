class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        
        int ones = 0;
        for (int num: arr) {
            ones += num;
        }
        
        if (ones % 3 != 0) {
            return {-1, -1};
        }
        
        int onesPerPart = ones / 3;
        
        if (onesPerPart == 0) {
            return {0, n-1};
        }
        
        int partOne, partTwo, partThree;
        int sum = 0;
        for (int idx=0; idx<n; idx++) {
            if (arr[idx] == 1) {
                sum++;
                
                if (sum == 1) {
                    partOne = idx;
                } else if (sum == onesPerPart + 1) {
                    partTwo = idx;
                } else if (sum == onesPerPart * 2 + 1) {
                    partThree = idx;
                }
            }
        }
        
        while (partThree < n && arr[partOne] == arr[partTwo] && arr[partTwo] == arr[partThree]) {
            partOne++;
            partTwo++;
            partThree++;
        }
        
        if (partThree == n) {
            return {partOne-1, partTwo};
        }
        
        return {-1, -1};
    }
};