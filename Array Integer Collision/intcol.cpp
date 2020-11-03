class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        deque<int> dq;
        dq.push_back(asteroids[0]);
        bool lastSurvived;
        for (int i=1; i<asteroids.size(); i++) {
            lastSurvived = true;
            while (dq.size() > 0 && dq.back() > 0 && asteroids[i] < 0) {
                if (abs(dq.back()) > abs(asteroids[i])) {
                    lastSurvived = false;
                    break;
                } else if (abs(dq.back()) == abs(asteroids[i])) {
                    lastSurvived = false;
                    dq.pop_back();
                    break;
                } else {
                    dq.pop_back();
                }
            }
            if (lastSurvived == true) {
                dq.push_back(asteroids[i]);
            }
        }
        
        for (int i=0; i<dq.size(); i++) {
            ans.push_back(dq[i]);
        }
        return ans;
    }
};