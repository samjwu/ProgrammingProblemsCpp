class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (freeTimeSlot(start, end)) {
            intervals.insert({start, end});
            return true;
        }
        
        return false;
    }
    
private:
    set<pair<int, int>> intervals;
    
    bool freeTimeSlot(int start, int end) {
        set<pair<int, int>>::iterator next = intervals.lower_bound({start, end});
        
        if (next != intervals.end() && next->first < end) {
            return false;
        }
        
        if (next != intervals.begin() && (--next)->second > start) {
            return false;
        }
        
        intervals.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */