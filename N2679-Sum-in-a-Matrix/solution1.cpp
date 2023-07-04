class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0;
        int m = nums.size();
        int n = nums[0].size();
        vector<priority_queue<int>> pq(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq[i].emplace(nums[i][j]);
            }
        }
        for (int j = 0; j < n; j++) {
            int maxVal = 0;
            for (int i = 0; i < m; i++) {
                maxVal = max(maxVal, pq[i].top());
                pq[i].pop();
            }
            res += maxVal;
        }
        return res;
    }
};
