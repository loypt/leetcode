class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        unordered_set<int> used;
        int res = 0;
        for(char c : s){
            ++cnt[c-'a'];
        }

        for(int i = 0; i < 26; ++i){
            for(; cnt[i] > 0 && !used.insert(cnt[i]).second; --cnt[i]){
                ++res;
            }
        }
        return res;
    }
};
