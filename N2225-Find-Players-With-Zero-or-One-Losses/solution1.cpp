class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> freq;
        for (const auto& match: matches) {
            int winner = match[0], loser = match[1];
            if (!freq.count(winner)) {
                freq[winner] = 0;
            }
            ++freq[loser];
        }

        vector<vector<int>> ans(2);
        for (const auto& [key, value]: freq) {
            if (value < 2) {
                ans[value].push_back(key);
            }
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
