class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> rights;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                rights.push_back(i - 1);
            }
        }
        rights.push_back(n - 1);

        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0];
            int y = queries[i][1];

            res[i] = ranges::lower_bound(rights, x) == ranges::lower_bound(rights, y);
        }
        return res;
    }
};
