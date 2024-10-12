class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<vector<int>> A;
        for (auto& v : intervals) {
            A.push_back({v[0], 1});
            A.push_back({v[1] + 1, -1});
        }
        int res = 0, cur = 0;
        sort(A.begin(), A.end());
        for (auto& v : A)
            res = max(res, cur += v[1]);
        return res;
    }
};
