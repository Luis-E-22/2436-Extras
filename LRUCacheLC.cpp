class LRUCache {
    int cap;
    list<pair<int,int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) {
       cap = capacity; 
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        auto it = mp[key];
        int val = it->second;
        dq.erase(it);
        dq.push_front({key, val});
        mp[key] = dq.begin();
        return val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            dq.erase(mp[key]);
        } else if (dq.size() == cap) {
            auto last = dq.back();
            mp.erase(last.first);
            dq.pop_back();
        }
        dq.push_front({key, value});
        mp[key] = dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */