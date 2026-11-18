class MyHashSet {
public:
    bool vec[1000001];
    MyHashSet() {
        for(int i=0;i<1000001;i++) vec[i] = false;
        
    }
    
    void add(int key) {
        vec[key] = true;
        
    }
    
    void remove(int key) {
        vec[key] = false;
    }
    
    bool contains(int key) {
        return vec[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */