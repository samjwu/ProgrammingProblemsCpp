class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        
        vector<vector<int>> graph(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i != j) {
                    graph[i][j] = calcExtraLen(words[i], words[j]);
                    graph[j][i] = calcExtraLen(words[j], words[i]);
                }
            }
        }
        
        // mask of n bits representing visited set of nodes (eg: 101 means visited nodes 0 and 2 for 0-indexed nodes)
        int pow2n = 1 << n;
        vector<vector<int>> memo(pow2n, vector<int>(n, INT_MAX)); // for memo[i][j], gives lowest path length ending with node j in visited set i
        vector<vector<int>> path(pow2n, vector<int>(n)); // for path[i][j], gives visited node before j in visited set i
        int lastVisitedNode = -1;
        int lowestPathLen = INT_MAX;
        
        for (int i=1; i<pow2n; i++) {
            for (int j=0; j<n; j++) {
                if ((i & (1 << j)) > 0) { // if current node is in visited set
                    int prevVisitedSet = i - (1 << j); // remove current node from visited set
                    
                    if (prevVisitedSet == 0) {
                        memo[i][j] = words[j].length();
                        
                    } else {
                        for (int k=0; k<n; k++) {
                            if (memo[prevVisitedSet][k] < INT_MAX && memo[prevVisitedSet][k] + graph[k][j] < memo[i][j]) { // if path length visiting node k before ending at node j is lower than previously recorded one
                                memo[i][j] = memo[prevVisitedSet][k] + graph[k][j];
                                path[i][j] = k;
                            }
                        }
                    }
                }
                
                if (i == pow2n - 1 && memo[i][j] < lowestPathLen) {
                    lowestPathLen = memo[i][j];
                    lastVisitedNode = j;
                }
            }
        }
        
        int currVisitedSet = pow2n - 1;
        stack<int> stk;
        while (currVisitedSet > 0) {
            stk.push(lastVisitedNode);
            int tmp = currVisitedSet;
            currVisitedSet -= (1 << lastVisitedNode);
            lastVisitedNode = path[tmp][lastVisitedNode];
        }
        
        string ans;
        int i = stk.top();
        stk.pop();
        ans.append(words[i]);
        while (!stk.empty()) {
            int j = stk.top();
            stk.pop();
            ans.append(words[j].substr(words[j].length() - graph[i][j]));
            i = j;
        }
        return ans;
    }
    
private:
    // return length of b minus overlap of a and b
    int calcExtraLen(string a, string b) {
        for (int k=1; k<a.length(); k++) {
            // if start of b matches with end of a
            if (a.substr(k).compare(b.substr(0, a.length()-k)) == 0) {
                return b.length() - (a.length() - k);
            }
        }
        
        return b.length();
    }
};