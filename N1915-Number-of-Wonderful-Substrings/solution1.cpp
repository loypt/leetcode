class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> freq = {{0, 1}};
        int mask = 0;
        long long ans = 0;
        for (char ch: word) {
            int idx = ch - 'a';
            mask ^= (1 << idx);
            if (freq.count(mask)) {
                ans += freq[mask];
            }
            for (int i = 0; i < 10; ++i) {
                if (int mask_pre = mask ^ (1 << i); freq.count(mask_pre)) {
                    ans += freq[mask_pre];
                }
            }
            ++freq[mask];
        }
        return ans;
    }
};
