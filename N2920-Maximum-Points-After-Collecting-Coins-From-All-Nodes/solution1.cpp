class Solution {
private:
    vector<vector<int>> memo;
    vector<vector<int>> children;

public:
    int dfs(int node, int parent, int f, vector<int> &coins, int k) {
        if (memo[node][f] >= 0) {
            return memo[node][f];
        }
        int res0 = (coins[node] >> f) - k, res1 = coins[node] >> (f + 1);
        for (int child : children[node]) {
            if (child == parent) {
                continue;
            }
            res0 += dfs(child, node, f, coins, k);
            if (f + 1 < 14) {
                res1 += dfs(child, node, f + 1, coins, k);
            }
        }
        return memo[node][f] = max(res0, res1);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        children = vector<vector<int>>(n);
        for (const auto &edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        memo = vector<vector<int>>(n, vector<int>(14, -1));
        return dfs(0, -1, 0, coins, k);
    }
};
