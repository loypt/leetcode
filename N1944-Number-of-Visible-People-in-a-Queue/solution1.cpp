class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n), stack;
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && heights[stack.back()] <= heights[i])
                res[stack.back()]++, stack.pop_back();
            if (!stack.empty())
                res[stack.back()]++;
            stack.push_back(i);
        }
        return res;
    }
};
