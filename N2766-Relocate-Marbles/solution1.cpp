class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        vector<int> ans;
        unordered_map<int, bool> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = true;
        }

        for (int i = 0; i < moveFrom.size(); i++) {
            mp.erase(moveFrom[i]);
            mp[moveTo[i]] = true;
        }

        for (const auto& pair : mp) {
            ans.push_back(pair.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
