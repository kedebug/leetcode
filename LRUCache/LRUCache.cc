class LRUCache{
public:
    LRUCache(int capacity) {
        cap_ = capacity;
        dummy_.prev = &dummy_;
        dummy_.next = &dummy_;
    }
    
    int get(int key) {
        if (cache_.find(key) == cache_.end()) {
            return -1;
        }
        entry* e = cache_[key];
        e->prev = &dummy_;
        e->next = dummy_.next;
        dummy_.next->prev = e;
        dummy_.next = e;
        
        return e->val;
    }
    
    void set(int key, int value) {
        while (cache_.size() >= cap_) {
            entry* e = dummy_.prev;
            e->prev->next = &dummy_;
            dummy_.prev = e->prev;
            
            cache_.erase(e->key);
            delete(e);
        }
        
        entry* e;
        if (cache_.find(key) == cache_.end()) {
            e = new(entry);
            cache_[key] = e;
        } else {
            e = cache_[key];
            e->prev->next = e->next;
            e->next->prev = e->prev;
        }
        e->prev = &dummy_;
        e->next = dummy_.next;
        dummy_.next->prev = e;
        dummy_.next = e;
        
        e->val = value;
    }
    
private:
    struct entry {
        int key;
        int val;
        entry* prev;
        entry* next;
    };
    
    int cap_;
    map<int, entry*> cache_;
    struct entry dummy_;
};
