class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        long long cur = 0;
        for (char& c : word) {
            cur = (cur * 10 + (c - '0')) % m;
            res.push_back(cur == 0 ? 1 : 0);
        }
        return res;
    }
};
