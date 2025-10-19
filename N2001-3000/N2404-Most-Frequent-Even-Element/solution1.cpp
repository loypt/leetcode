class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto x : nums) {
            if (x % 2 == 0) {
                count[x]++;
            }
        }
        int res = -1, ct = 0;
        for (auto &p : count) {
            if (res == -1 || p.second > ct || p.second == ct && res > p.first) {
                res = p.first;
                ct = p.second;
            }
        }
        return res;
    }
};
