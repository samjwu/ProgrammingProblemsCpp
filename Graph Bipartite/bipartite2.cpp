class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int node, int color) {
        if (!colors[node]) {
            int val = 1;
            if (color == -1) {
                val = -1;
            } 
            colors[node] = val;
            
            for (int neighbor: graph[node]) {
                if (!dfs(graph, colors, neighbor, -val)) {
                    return false;
                }
            }
        }
        
        return !color || color == colors[node];
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n); // {-1, 0, 1} = {A, none, B}
        
        for (int i=0; i<n; i++) {
            if (!dfs(graph, colors, i, colors[i])) {
                return false;
            }
        }
        
        return true;
    }
};