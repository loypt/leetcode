class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        int res = 0;
        vector<vector<int>> g(n);
        for (const auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        function<int(int, int)> dfs = [&](int node, int parent) -> int {
            bool valid = true;
            int treeSize = 0;
            int subTreeSize = 0;

            for (int child : g[node]) {
                if (child != parent) {
                    int size = dfs(child, node);
                    if (subTreeSize == 0) {
                        subTreeSize = size;
                    } else if (size != subTreeSize) {
                        valid = false;
                    }
                    treeSize += size;
                }
            }
            if (valid) {
                res++;
            }
            return treeSize + 1;
        };

        dfs(0, -1);
        return res;
    }
};
