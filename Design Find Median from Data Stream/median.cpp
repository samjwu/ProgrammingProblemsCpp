class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (equalSize) { // rebalance and add num to maxHeap
            minHeap.push(num);
            
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else { // rebalance and add num to minHeap
            maxHeap.push(num);
            
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        equalSize = !equalSize;
    }
    
    double findMedian() {
        if (equalSize) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        
        return maxHeap.top();
    }
    
private:
    priority_queue<int, vector<int>, less<int>> maxHeap; // small half
    priority_queue<int, vector<int>, greater<int>> minHeap; // large half
    bool equalSize = true; // true if heaps are equal size, else false
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */