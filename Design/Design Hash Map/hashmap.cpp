class MyHashMap {
public:
    int size = 10000;
    vector<vector<pair<int, int>>> map;
    
    /** Initialize your data structure here. */
    MyHashMap() {
        map.resize(size);
    }
    
    int hash(int key) {
        return key % size;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key);
        auto &pairs = map[h];
        for (auto &pair: pairs) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        pairs.push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hash(key);
        auto &pairs = map[h];
        for (auto pair: pairs) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        auto &pairs = map[h];
        for (auto it = pairs.begin(); it != pairs.end(); it++) {
            if (it->first == key) {
                pairs.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */