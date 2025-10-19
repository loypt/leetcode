class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size(), res = n;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
        for (auto& pos : mp) {
            int mx = pos.second[0] + n - pos.second.back();
            for (int i = 1; i < pos.second.size(); ++i) {
                mx = max(mx, pos.second[i] - pos.second[i - 1]);
            }
            res = min(res, mx / 2);
        }
        return res;
    }
};
