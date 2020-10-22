class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        bool lastSurvived;
        for (int asteroid:asteroids) {
            lastSurvived = true;
            while (ans.size() > 0 && ans.back() > 0 && asteroid < 0 && lastSurvived == true) {
                if (ans.back() >= abs(asteroid)) {
                    lastSurvived = false;
                }
                if (ans.back() <= abs(asteroid)) {
                    ans.pop_back();
                }
            }
            if (lastSurvived == true) {
                ans.push_back(asteroid);
            }
        }
        return ans;
    }

};