class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n);
        unordered_map<int, int> cnt;
        for (auto edge : edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            if (x > y) {
                swap(x, y);
            }
            degree[x]++;
            degree[y]++;
            cnt[x * n + y]++;
        }

        vector<int> arr = degree;
        vector<int> ans;
        sort(arr.begin(), arr.end());
        for (int bound : queries) {
            int total = 0;
            for (int i = 0; i < n; i++) {
                int j = upper_bound(arr.begin() + i + 1, arr.end(), bound - arr[i]) - arr.begin();
                total += n - j;
            }
            for (auto &[val, freq] : cnt) {
                int x = val / n;
                int y = val % n;
                if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound) {
                    total--;
                }
            }
            ans.emplace_back(total);
        }

        return ans;
    }
};
