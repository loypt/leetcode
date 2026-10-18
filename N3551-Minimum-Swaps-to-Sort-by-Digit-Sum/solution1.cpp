class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = (int)nums.size();
        auto digitSum = [](int x) {
            int s = 0;
            while (x > 0) { s += x % 10; x /= 10; }
            return s;
        };
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            int sa = digitSum(nums[a]), sb = digitSum(nums[b]);
            if (sa != sb) return sa < sb;
            return nums[a] < nums[b];
        });
        // pos[i] = target index of the element at original index i
        vector<int> pos(n);
        for (int t = 0; t < n; ++t) pos[idx[t]] = t;
        vector<char> vis(n, 0);
        int cycles = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            ++cycles;
            for (int j = i; !vis[j]; j = pos[j]) vis[j] = 1;
        }
        return n - cycles;
    }
};
