class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<bool> visited(n, false);
        
        visited[0] = true;
        for (int key: rooms[0]) {
            q.push(key);
        }
        
        while (!q.empty()) {
            int key = q.front();
            q.pop();
            visited[key] = true;
            
            for (int nextKey: rooms[key]) {
                if (!visited[nextKey]) {
                    q.push(nextKey);
                }
            }
        }
        
        int sawRooms = count(visited.begin(), visited.end(), true);
        return sawRooms == n;
    }
};