class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        long long total = accumulate(beans.begin(), beans.end(), 0LL);
        long long res = total;
        for (int i = 0; i < n; i++) {
            res = min(res, total - (long long)beans[i] * (n - i));
        }
        return res;
    }
};
