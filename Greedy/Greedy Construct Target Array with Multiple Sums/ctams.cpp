class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        priority_queue<int, vector<int>, less<int>> maxHeap(target.begin(), target.end());
        
        long long sum = 0;
        for (int num: target) {
            sum += num;
        }
        
        while (sum > n) {
            int highest = maxHeap.top();
            maxHeap.pop();
            
            sum -= highest;
            if (highest == 1 || sum == 1) {
                return true;
            }
            if (sum <= 0 || highest % sum == 0 || highest < sum) {
                return false;
            }
            
            int reduced = highest % sum;
            maxHeap.push(reduced);
            
            sum += reduced;
        }
        
        return sum == n;
    }
};