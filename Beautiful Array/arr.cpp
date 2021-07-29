class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        for (int i=0; i<n; i++) {
            ans.push_back(i+1);
        }
        partitionSort(ans, 0, n-1, 1);
        return ans;
    }
    
private:
    int partition(vector<int> &v, int start, int end, int mask) {
        int j = start;
        
        for (int i=start; i<=end; i++) {
            if ((v[i] & mask) != 0) {
                swap(v[i], v[j]);
                j++;
            }
        }
        
        return j;
    }
    
    void partitionSort(vector<int> & v, int start, int end, int mask)
    {
        if (start >= end) {
            return;
        }
        
        int mid = partition(v, start, end, mask);
        
        partitionSort(v, start, mid - 1, mask << 1);
        partitionSort(v, mid, end, mask << 1);
    }
};