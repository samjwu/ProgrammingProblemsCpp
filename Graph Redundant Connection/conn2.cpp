class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for (int i=1; i<n+1; i++) {
            parent[i] = i;
        }
        
        for (auto edge: edges) {
            if (unify(edge[0], edge[1])) {
                return edge;
            }
        }
        
        return {};
    }
    
private:
    vector<int> parent;
    
    // find parent of node; use path compression to update parent during call
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        
        parent[x] = find(parent[x]);
        return parent[x];
    }
    
    // if nodes x and y have same parent, cycle exists; otherwise set x and y to same parent
    bool unify(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);
        
        if (xParent == yParent) {
            return true;
        }
        
        parent[xParent] = yParent;
        return false;
    }
};