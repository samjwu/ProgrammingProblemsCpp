class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int> set;
        int last = arr[arr.size() - 1];
        
        for (int i = 1; i <= last; i++) {
            set.insert(i);    
        }
        
        for (int n : arr) {
            set.erase(n);
        }
        
        auto it = set.begin();
        int idx = 1;
        while (it != set.end()) {
            if (idx == k) {
                return *it;
            }
            it++;
            idx++;
        }
        
        while (idx <= k) {
            last++;
            idx++;
        }
        
        return last;
    }
};