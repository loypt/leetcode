class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int pre = maxHeights[i];
            long long sum = pre;
            for (int j = i - 1; j >= 0; j--) {
                pre = min(pre, maxHeights[j]);
                sum += pre;
            }
            int suf = maxHeights[i];
            for (int j = i + 1; j < n; j++) {
                suf = min(suf, maxHeights[j]);
                sum += suf;
            }
            res = max(res, sum);
        }
        return res;
    }
};
