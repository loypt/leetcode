class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for (auto &v : items1) {
            mp[v[0]] += v[1];
        }
        for (auto &v : items2) {
            mp[v[0]] += v[1];
        }

        vector<vector<int>> res;
        for (auto &[k, v] : mp) {
            res.push_back({k, v});
        }
        return res;
    }
};
