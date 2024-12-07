class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        bool flag[n + 1];
        memset(flag, 0, sizeof(flag));
        for (int x : banned) if (x <= n) flag[x] = true;

        int ans = 0;
        long long sm = 0;
        for (int i = 1; i <= n; i++) if (!flag[i]) {
            if (sm + i > maxSum) break;
            ans++;
            sm += i;
        }
        return ans;
    }
};
