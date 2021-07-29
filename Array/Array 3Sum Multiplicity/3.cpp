class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long ans = 0;
        int mod = pow(10, 9) + 7;
        
        sort(arr.begin(), arr.end());
        
        for (int i=0; i<arr.size(); i++) {
            int diff = target - arr[i];
            int j = i+1;
            int k = arr.size()-1;
            
            while (j < k) {
                int sum = arr[j] + arr[k];
                
                if (sum < diff) {
                    j++;
                } else if (sum > diff) {
                    k--;
                } else if (arr[j] != arr[k]) {
                    int jCount = 1;
                    int kCount = 1;
                    
                    while (arr[j] == arr[j+1]) {
                        jCount++;
                        j++;
                    }
                    
                    while (arr[k-1] == arr[k]) {
                        kCount++;
                        k--;
                    }
                    
                    ans += jCount * kCount;
                    ans %= mod;
                    j++;
                    k--;
                } else {
                    ans += (k-j+1) * (k-j) / 2;
                    ans %= mod;
                    break;
                }
            }
        }
        
        return (int) ans;
    }
};