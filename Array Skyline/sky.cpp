class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> points;
        
        for (auto building : buildings) {
            points.push_back(make_pair(building[0], -building[2]));
            points.push_back(make_pair(building[1], building[2]));
        }
        
        sort(points.begin(), points.end());
        
        multiset<int> heights = {0};
        int max_height = 0;
        int curr_height = 0;
        
        for (auto point : points) {
            if (point.second < 0) {
                heights.insert(-point.second);
            } else {
                heights.erase(heights.find(point.second));
            }
            
            curr_height = *heights.rbegin();
            if (curr_height != max_height) {
                ans.push_back({point.first, curr_height});
                max_height = curr_height;
            }
        }
        
        return ans;
    }
};