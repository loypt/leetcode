class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for(int x : arr){
            ++cnt[x];
        }
        if(cnt[0] % 2){
            return false;
        }
        vector<int> vals;
        vals.reserve(cnt.size());
        for(auto &[x, _] : cnt){
            vals.push_back(x);
        }
        sort(vals.begin(), vals.end(), [](int x, int y){return abs(x) < abs(y);});

        for(int x : vals){
            if(cnt[2*x]< cnt[x]){
                return false;
            }
            cnt[2*x] -= cnt[x];
        }
        return true;
    }
};
