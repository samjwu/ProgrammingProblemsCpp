/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        listBegin.push(nestedList.begin());
        listEnd.push(nestedList.end());
    }
    
    int next() {
        return listBegin.top()++->getInteger();
    }
    
    bool hasNext() {
        while (listBegin.size() > 0) {
            auto top = listBegin.top();
            
            if (top == listEnd.top()) {
                listBegin.pop();
                listEnd.pop();
                continue;
            }
            
            if (top->isInteger()) {
                break;
            }
            
            listBegin.top()++;
            
            listBegin.push((top->getList()).begin());
            listEnd.push((top->getList()).end());
        }
        
        return listBegin.size() > 0;
    }

private:
    stack<vector<NestedInteger>::iterator> listBegin, listEnd;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */