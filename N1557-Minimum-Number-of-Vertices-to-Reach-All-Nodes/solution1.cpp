class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        auto ans = vector<int>();
        auto endSet = unordered_set<int>();
        for (auto edge : edges) {
            endSet.insert(edge[1]);
        }
        for (int i = 0; i < n; i++) {
            if (endSet.find(i) == endSet.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
