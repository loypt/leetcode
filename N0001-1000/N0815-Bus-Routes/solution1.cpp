class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        int n = routes.size();
        vector<vector<int>> edge(n, vector<int>(n));
        unordered_map<int, vector<int>> rec;
        for (int i = 0; i < n; i++) {
            for (int site : routes[i]) {
                for (int j : rec[site]) {
                    edge[i][j] = edge[j][i] = true;
                }
                rec[site].push_back(i);
            }
        }

        vector<int> dis(n, -1);
        queue<int> que;
        for (int bus : rec[source]) {
            dis[bus] = 1;
            que.push(bus);
        }
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            for (int y = 0; y < n; y++) {
                if (edge[x][y] && dis[y] == -1) {
                    dis[y] = dis[x] + 1;
                    que.push(y);
                }
            }
        }

        int ret = INT_MAX;
        for (int bus : rec[target]) {
            if (dis[bus] != -1) {
                ret = min(ret, dis[bus]);
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};
