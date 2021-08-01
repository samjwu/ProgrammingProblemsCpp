class UnionFind {
public:
    UnionFind(int m, int n) {
        int elements = m*n + 1;
        parent.resize(elements);
        groupSize.resize(elements);
        
        for (int i=0; i<elements; i++) {
            parent[i] = i;
            groupSize[i] = 1;
        }
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        
        return parent[x];
    }
    
    void unify(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return;
        }
        
        if (groupSize[rootX] >= groupSize[rootY]) {
            parent[rootY] = rootX;
            groupSize[rootX] += groupSize[rootY];
        } else {
            parent[rootX] = rootY;
            groupSize[rootY] += groupSize[rootX];
        }
    }
    
    int getSize(int x) {
        int rootX = find(x);
        return groupSize[rootX];
    }
    
private:
    vector<int> parent;
    vector<int> groupSize;
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        UnionFind uf(m, n);
        int ans = 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    if (i>0 && grid[i-1][j] == 1) {
                        uf.unify(i*n + j, (i-1)*n + j);
                    }
                    if (i<m-1 && grid[i+1][j] == 1) {
                        uf.unify(i*n + j, (i+1)*n + j);
                    }
                    if (j>0 && grid[i][j-1] == 1) {
                        uf.unify(i*n + j, i*n + j-1);
                    }
                    if (j<n-1 && grid[i][j+1] == 1) {
                        uf.unify(i*n + j, i*n + j+1);
                    }
                }
            }
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, uf.getSize(i*n + j));
                }
            }
        }
        
        return ans;
    }
};