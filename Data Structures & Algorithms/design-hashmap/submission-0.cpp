class MyHashMap {
public:
    vector<int*> vec;
    MyHashMap() {vec.resize(1000001,nullptr);
        
    }
    
    void put(int key, int value) {
        if(vec[key])
        {
            *vec[key] = value;
            return;
        }
        int* i = new int(value);
        vec[key] = i;
    }
    
    int get(int key) {
        if(vec[key]) return *vec[key];
        return -1;
        
    }
    
    void remove(int key) {
        vec[key] = nullptr;
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */