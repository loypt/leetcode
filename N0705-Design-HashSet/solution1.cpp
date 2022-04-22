class MyHashSet {
public:
    MyHashSet() : data(base) {}
    
    void add(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); it++){
            if((*it) == key){
                return;
            }
        }
        data[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) {
                data[h].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) {
                return true;
            }
        }
        return false;
    }

private:
    vector<list<int>> data;
    static const int base = 857;
    static int hash(int key){
        return key%base;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
