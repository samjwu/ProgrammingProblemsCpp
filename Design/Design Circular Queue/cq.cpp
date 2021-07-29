class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        cq = vector<int>(k);
        currsz = 0;
        sz = k;
        head = 0;
        tail = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        
        cq[tail] = value;
        tail = (tail + 1) % sz;
        currsz++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        
        head = (head + 1) % sz;
        currsz--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        
        return cq[head];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        
        if (tail == 0) {
            return cq[sz-1];
        }
        return cq[tail-1];
    }
    
    bool isEmpty() {
        return currsz == 0;
    }
    
    bool isFull() {
        return currsz == sz;
    }
    
private:
    vector<int> cq;
    int sz;
    int currsz;
    int head, tail;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */