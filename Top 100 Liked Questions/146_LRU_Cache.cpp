class LRUCache {
    int capacity;
    list<int> cacheline;
    unordered_map<int, pair<int,list<int>::iterator>> m; // pair<value, position>
public:
    LRUCache(int capacity_) {
        cacheline.resize(capacity_);
        capacity = capacity_;
    }
    
    int get(int key) {
        if(m.find(key)!= m.end()){
            cacheline.erase(m[key].second);
            cacheline.push_front(key);
            m[key].second = cacheline.begin();
            return m[key].first;
        }
        else//cache miss
        {
            return -1;   
        }
    }
    
    void put(int key, int value) {
        //key exists
        if(m.find(key)!= m.end()){
            cacheline.erase(m[key].second);
            cacheline.push_front(key);
            m[key].second = cacheline.begin();
            m[key].first = value;
        }
        else{
            //key is not found
            //evict if the cacheline is full
            if(cacheline.size() == capacity){
                int evict = cacheline.back();
                cacheline.pop_back();
                m.erase(evict);  
            }
            //else insert the key
            cacheline.push_front(key);
            m[key].second = cacheline.begin();
            m[key].first = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */