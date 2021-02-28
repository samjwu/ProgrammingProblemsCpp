class FreqStack {
public:
    map<int, int> freqMap;
    map<int, stack<int>> stkMap;
    int maxFreq;
    
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int x) {
        freqMap[x]++;
        maxFreq = max(maxFreq, freqMap[x]);
        stkMap[freqMap[x]].push(x);
    }
    
    int pop() {
        int x = stkMap[maxFreq].top();
        stkMap[maxFreq].pop();
        freqMap[x]--;
        if (stkMap[maxFreq].empty()) {
            maxFreq--;
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */