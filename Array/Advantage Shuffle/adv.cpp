class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> Asorted(A.begin(), A.end());
        sort(Asorted.begin(), Asorted.end());
        
        unordered_map<int, int> freq;
        
        for (int num: A) {
            freq[num]++;
        }
        
        vector<int> ans;
        
        for (int num: B) {
            bool found = false;
            
            for (int i=0; i<Asorted.size(); i++) {
                if (num < Asorted[i] && freq[Asorted[i]] > 0) {
                    ans.push_back(Asorted[i]);
                    freq[Asorted[i]]--;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                for (int i=0; i<Asorted.size(); i++) {
                    if (freq[Asorted[i]] > 0) {
                        ans.push_back(Asorted[i]);
                        freq[Asorted[i]]--;
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};