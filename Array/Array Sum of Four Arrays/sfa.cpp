class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> ab, cd;
        int ans = 0;
        
        for (int a : A) {
            for (int b : B) {
                ab[a + b]++;
            }
        }
        for (int c : C) {
            for (int d : D) {
                cd[c + d]++;
            }
        }
        
        for (auto p : ab) {
            ans += p.second * cd[-p.first];
        }
        
        return ans;
    }
};