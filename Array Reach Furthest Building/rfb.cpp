class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, less<int>> maxHeap;
        
        int jumpSum = 0;
        
        for (int i=1; i<heights.size(); i++) {
            if (heights[i-1] >= heights[i]) {
                continue;
            } else {
                int diff = heights[i] - heights[i-1];
                if (jumpSum + diff <= bricks) {
                    jumpSum += diff;
                    maxHeap.push(diff);
                } else if (jumpSum + diff > bricks && ladders > 0) {
                    if (!maxHeap.empty()) {
                        int biggestJump = maxHeap.top();
                        if (diff < biggestJump) {
                            maxHeap.pop();
                            jumpSum -= biggestJump;
                            jumpSum += diff;
                            maxHeap.push(diff);                    
                        }
                    }
                    ladders -= 1;
                } else {
                    return i-1;
                }
            }
        }
        
        return heights.size()-1;
    }
};