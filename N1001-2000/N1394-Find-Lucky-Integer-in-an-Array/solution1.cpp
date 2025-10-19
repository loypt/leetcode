class Solution {
public:
    unordered_map <int, int> m;
    int findLucky(vector<int>& arr) {
        for (auto x: arr) {
            ++m[x];
        }
        int ans = -1;
        for (auto [key, value]: m) {
            if (key == value) {
                ans = max(ans, key);
            }
        }
        return ans;
    }
};
