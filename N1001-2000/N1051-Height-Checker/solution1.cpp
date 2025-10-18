class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto cpy = heights;
        sort(cpy.begin(), cpy.end());
        return transform_reduce(begin(heights), end(heights), begin(cpy), 0, plus<>(), not_equal_to<>());
    }
};
