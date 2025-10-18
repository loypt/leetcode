class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int, int>> sortedNums;
        vector<tuple<int, int, int>> sortedQueries;
        for (int i = 0; i < nums1.size(); i++) {
            sortedNums.emplace_back(nums1[i], nums2[i]);
        }
        sort(sortedNums.begin(), sortedNums.end(), greater<pair<int, int>>());
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.emplace_back(i, queries[i][0], queries[i][1]);
        }
        sort(sortedQueries.begin(), sortedQueries.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
            return get<1>(a) > get<1>(b);
        });

        vector<pair<int, int>> stk;
        vector<int> answer(queries.size(), -1);
        int j = 0;
        for (auto &[i, x, y] : sortedQueries) {
            while (j < sortedNums.size() && sortedNums[j].first >= x) {
                auto [num1, num2] = sortedNums[j];
                while (!stk.empty() && stk.back().second <= num1 + num2) {
                    stk.pop_back();
                }
                if (stk.empty() || stk.back().first < num2) {
                    stk.emplace_back(num2, num1 + num2);
                }
                j++;
            }
            int k = lower_bound(stk.begin(), stk.end(), make_pair(y, 0)) - stk.begin();
            if (k < stk.size()) {
                answer[i] = stk[k].second;
            }
        }            
        return answer;
    }
};
