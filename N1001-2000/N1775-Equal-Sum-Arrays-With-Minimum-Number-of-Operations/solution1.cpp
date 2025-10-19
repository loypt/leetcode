class Solution {
public:
    int help(vector<int>& h1, vector<int>& h2, int diff) {
        vector<int> h(7, 0);
        for (int i = 1; i < 7; ++i) {
            h[6 - i] += h1[i];
            h[i - 1] += h2[i];
        }
        int res = 0;
        for (int i = 5; i && diff > 0; --i) {
            int t = min((diff + i - 1) / i, h[i]);
            res += t;
            diff -= t * i;
        }
        return res;
    }

    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (6 * n < m || 6 * m < n) {
            return -1;
        }
        vector<int> cnt1(7, 0), cnt2(7, 0);
        int diff = 0;
        for (auto& i : nums1) {
            ++cnt1[i];
            diff += i;
        }
        for (auto& i : nums2) {
            ++cnt2[i];
            diff -= i;
        }
        if (!diff) {
            return 0;
        }
        if (diff > 0) {
            return help(cnt2, cnt1, diff);
        }
        return help(cnt1, cnt2, -diff);
    }
};
