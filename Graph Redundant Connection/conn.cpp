class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<set<int>> graph(n+1);
        vector<int> ans;
        
        for (auto edge: edges) {
            if (hasCycle(graph, 0, edge[0], edge[1])) {
                ans = edge; // return last edge
            } else {
                // undirected graph
                graph[edge[0]].insert(edge[1]);
                graph[edge[1]].insert(edge[0]);
            }
        }
        
        return ans;
    }
    
private:
    bool hasCycle(vector<set<int>>& graph, int parent, int u, int v) {
        // source node u reached destination node v, found cycle
        if (u == v) {
            return true;
        }
        
        for (int neighbor: graph[u]) {
            // prevent going backwards in undirected graph
            if (neighbor == parent) {
                continue;
            }
            
            if (hasCycle(graph, u, neighbor, v)) {
                return true;
            }
        }
        
        return false;
    }
};