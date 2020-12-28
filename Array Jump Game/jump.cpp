class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) {
            return 0;
        }
        
        map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);
        }
        
        vector<int> currLayer;
        currLayer.push_back(0);
        set<int> visitedPos;
        int ans = 0;
        
        while (currLayer.size() > 0) {
            vector<int> nextLayer;
            
            for (int nodePos : currLayer) {
                if (nodePos == n - 1) {
                    return ans;
                }
                
                for (int nextPos : graph[arr[nodePos]]) {
                    if (visitedPos.find(nextPos) == visitedPos.end()) {
                        visitedPos.insert(nextPos);
                        nextLayer.push_back(nextPos);
                    }
                }
                
                graph[arr[nodePos]].clear();
                
                if (nodePos + 1 < n && visitedPos.find(nodePos + 1) == visitedPos.end()) {
                    visitedPos.insert(nodePos + 1);
                    nextLayer.push_back(nodePos + 1);
                }
                
                if (nodePos - 1 >= 0 && visitedPos.find(nodePos - 1) == visitedPos.end()) {
                    visitedPos.insert(nodePos - 1);
                    nextLayer.push_back(nodePos - 1);
                }
            }
            
            currLayer = nextLayer;
            ans++;
        }
        
        return ans;
    }
};