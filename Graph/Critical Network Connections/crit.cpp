class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        low = vector<int>(n);
        num = vector<int>(n, -1);
        count = 0;
        
        graph = vector<vector<int>>(n);
        for (int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for (int i=0; i<n; i++) {
            if (num[i] == -1) {
                dfs(i, i);
            }
        }
        
        return ans;
    }
    
private:
    void dfs(int u, int prev) {
        count++;
        low[u] = count;
        num[u] = count;
        
        for (int i=0; i<graph[u].size(); i++) {
            int v = graph[u][i];
            
            if (v == prev) {
                continue;
            }
            
            if (num[v] == -1) {
                dfs(v, u);
            }
            
            low[u] = min(low[u], low[v]);
            
            if (low[v] > num[u]) {
                ans.push_back({u, v});
            }
        }
    }
    
    vector<int> low; // SCC group
    vector<int> num; // counter during dfs
    
    int count;
    
    vector<vector<int>> graph;
    
    vector<vector<int>> ans;
};