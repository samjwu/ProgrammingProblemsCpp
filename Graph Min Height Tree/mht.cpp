class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        
        vector<vector<int>> tree(n);
        vector<int> in_degree(n, 0);
        for (vector<int> edge:edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
            in_degree[edge[0]]++;
            in_degree[edge[1]]++;
        }
        
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (in_degree[i] == 1) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                int node = q.front();
                q.pop();
                in_degree[node]--;
                
                if (n <= 2) {
                    ans.push_back(node);
                }
                
                for (int neighbor:tree[node]) {
                    in_degree[neighbor]--;
                    if (in_degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
            n -= size;
        }
        
        return ans;
    }
};