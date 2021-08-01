class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        for (int i=1; i<=key.length(); i++) {
            string prefix = key.substr(0, i);
            prefixMap[prefix] += val;
        }
        
        if (wordMap.find(key) != wordMap.end()) {
            for (int i=1; i<=key.length(); i++) {
                string prefix = key.substr(0, i);
                prefixMap[prefix] -= wordMap[key];
            }
        }
        
        wordMap[key] = val;
    }
    
    int sum(string prefix) {
        return prefixMap[prefix];
    }
    
private:
    map<string, int> prefixMap, wordMap;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */