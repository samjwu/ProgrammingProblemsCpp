class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string startState = "0000";
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        
        if (startState.compare(target) == 0) {
            return 0;
        }
        if (deadSet.find(startState) != deadSet.end()) {
            return -1;
        }
        
        unordered_set<string> visited;
        visited.insert(startState);
        
        queue<string> q;
        q.push(startState);
        
        int ans = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            
            for (int i=0; i<sz; i++) {
                string state = q.front();
                q.pop();
                
                vector<string> nextStates = getNextStates(state);
                for (string nextState: nextStates) {
                    if (nextState.compare(target) == 0) {
                        return ans+1;
                    }
                    if (visited.find(nextState) != visited.end()) {
                        continue;
                    }
                    if (deadSet.find(nextState) == deadSet.end()) {
                        visited.insert(nextState);
                        q.push(nextState);
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
    
private:
    vector<string> getNextStates(string state) {
        vector<string> nextStates;
        
        for (int i=0; i<4; i++) {
            string nextState = state;
            nextState[i] = (state[i] - '0' + 1) % 10 + '0';
            nextStates.push_back(nextState);
            nextState[i] = (state[i] - '0' - 1 + 10) % 10 + '0';
            nextStates.push_back(nextState);
        }
        
        return nextStates;
    }
};