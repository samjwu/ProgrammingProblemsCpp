class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n); // {-1, 0, 1} = {A, none, B}
        queue<int> q;
        
        for (int i=0; i<n; i++) {
            if (color[i] != 0) {
                continue;
            }
            
            color[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                
                for (int neighbor: graph[node]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
                
                q.pop();
            }
        }
        
        return true;
    }
};