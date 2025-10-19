class CountIntervals {
public:
    CountIntervals() {

    }
    
    void add(int left, int right) {
        auto interval = mp.upper_bound(right);
        if (interval != mp.begin()) {
            interval--;
        }
        while (interval != mp.end() && interval->first <= right && interval->second >= left) {
            int l = interval->first, r = interval->second;
            left = min(left, l);
            right = max(right, r);
            cnt -= r - l + 1;
            mp.erase(interval);
            interval = mp.upper_bound(right);
            if (interval != mp.begin()) {
                interval--;
            }
        }
        cnt += (right - left + 1);
        mp[left] = right;
    }
    
    int count() {
        return cnt;
    }
private:
    int cnt = 0;
    map<int, int> mp;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
