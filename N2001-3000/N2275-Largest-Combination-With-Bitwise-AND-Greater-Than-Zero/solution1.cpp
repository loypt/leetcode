class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        auto maxlen = [&](int k) -> int {
            int res = 0;
            for (int num: candidates) {
                if (num & (1 << k)) {
                    ++res;
                }
            }
            return res;
        };
        
        int res = 0;
        for (int i = 0; i < 24; ++i) {
            res = max(res, maxlen(i));
        }
        return res;
    }
};
