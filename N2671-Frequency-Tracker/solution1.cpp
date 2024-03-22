class FrequencyTracker {
public:
    unordered_map<int, int> mp;
    unordered_map<int, unordered_set<int>> mps;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(mp.find(number) != mp.end()){
            int f = mp[number];
            mps[f].erase(number);
        }
        mp[number]++;
        mps[mp[number]].insert(number);
    }
    
    void deleteOne(int number) {
        if(mp.find(number) != mp.end() && mp[number] > 0){
            int f = mp[number];
            mps[f].erase(number);
            mp[number]--;
            if(mp[number]){
                mps[mp[number]].insert(number);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return (mps[frequency].size() > 0);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
