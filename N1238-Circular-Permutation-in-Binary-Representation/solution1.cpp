class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ret;
        ret.reserve(1 << n);
        ret.push_back(start);
        for (int i = 1; i <= n; i++) {
            int m = ret.size();
            for (int j = m - 1; j >= 0; j--) {
                ret.push_back(((ret[j] ^ start) | (1 << (i - 1))) ^ start);
            }
        }
        return ret;
    }
};
