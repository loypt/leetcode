class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int i = n - k - 1, t{};
        vector ans(n, 0);
        iota(ans.begin(), ans.begin() + i, 1);
        generate_n(ans.begin() + i, k + 1, [&] { return (t = !t) ? ++i : n--; });
        return ans;
    }
};
