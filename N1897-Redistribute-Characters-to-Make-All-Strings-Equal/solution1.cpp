class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnt(26, 0);
        int n = words.size();
        for (const string& wd: words){
            for (char ch: wd){
                ++cnt[ch-'a'];
            }
        }
        return all_of(cnt.begin(), cnt.end(), [n](int x){ return x % n == 0; });
    }
};
