class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> ms(A.begin(), A.end());
        
        for (int i=0; i<B.size(); i++) {
            multiset<int>::iterator it = ms.upper_bound(B[i]);
            if (it == ms.end()) {
                it = ms.begin();
            }
            A[i] = *it;
            ms.erase(it);
        }
        
        return A;
    }
};