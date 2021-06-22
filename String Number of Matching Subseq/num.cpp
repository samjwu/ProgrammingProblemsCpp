class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int, int>>> waiting(128); //128 ascii chars
        
        for (int i=0; i<words.size(); i++) {
            waiting[words[i][0]].emplace_back(i, 1); //{wordNum i, letterNum j}
        }   
        
        for (char c: s) {
            vector<pair<int, int>> advance = waiting[c];
            waiting[c].clear();
            
            for (vector<pair<int, int>>::iterator it = advance.begin(); it != advance.end(); it++) {
                waiting[words[it->first][it->second++]].push_back(*it);
            }
        }
        
        return waiting[0].size(); //null terminated
    }
};