class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // BFS from sorted using inverse generators {R, L^{-1}}.
        // State (k, rev): config = L^k(s) or R L^k(s); dist = min ops to reach it from sorted.
        vector<int> dist(2 * n, -1);
        auto idx = [&](int k, int r) { return r * n + ((k % n + n) % n); };
        queue<pair<int,int>> q;
        dist[idx(0,0)] = 0;
        q.push({0,0});
        while (!q.empty()) {
            auto [k, r] = q.front(); q.pop();
            int d = dist[idx(k,r)];
            if (r == 0) {
                if (dist[idx(k-1,0)] == -1) { dist[idx(k-1,0)] = d+1; q.push({(k-1+n)%n,0}); }
                if (dist[idx(k,1)] == -1)   { dist[idx(k,1)] = d+1;   q.push({k,1}); }
            } else {
                if (dist[idx(k+1,1)] == -1) { dist[idx(k+1,1)] = d+1; q.push({(k+1)%n,1}); }
                if (dist[idx(k,0)] == -1)   { dist[idx(k,0)] = d+1;   q.push({k,0}); }
            }
        }
        int ans = INT_MAX;
        // rotation: nums[i] == (nums[0] + i) % n
        {
            int k = nums[0];
            bool ok = true;
            for (int i = 0; i < n; i++)
                if (nums[i] != (k + i) % n) { ok = false; break; }
            if (ok) ans = min(ans, dist[idx(k,0)]);
        }
        // reversed rotation: nums[i] == (n - 1 - i + k) % n
        {
            int k = (nums[0] - (n - 1)) % n; if (k < 0) k += n;
            bool ok = true;
            for (int i = 0; i < n; i++)
                if (nums[i] != (n - 1 - i + k) % n) { ok = false; break; }
            if (ok) ans = min(ans, dist[idx(k,1)]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
