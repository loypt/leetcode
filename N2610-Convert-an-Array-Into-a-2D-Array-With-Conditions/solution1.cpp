
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int>map;
        vector<vector<int>>ans;
        
        for (auto& t : nums) map[t]++;
        
        auto [_, n] = *max_element(map.begin(), map.end(), [&](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return a.second < b.second;
        });

        while (n--) {
            vector<int> tmp;
            for (auto& [num, cnt] : map) {
                if (cnt != 0) {   
                    tmp.emplace_back(num);
                    cnt--;
                }
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
