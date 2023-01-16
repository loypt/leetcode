class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;                    
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                ans.push_back(interval);
            }
            else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
