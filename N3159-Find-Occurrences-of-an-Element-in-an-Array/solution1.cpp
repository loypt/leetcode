class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                indices.emplace_back(i);
            }
        }
        vector<int> res;
        for (int q : queries) {
            if (indices.size() < q) {
                res.emplace_back(-1);
            } else {
                res.emplace_back(indices[q - 1]);
            }
        }
        return res;
    }
};
