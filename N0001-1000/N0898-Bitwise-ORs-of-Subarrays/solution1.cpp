class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        int n = nums.size();
        vector<int> ors; 
        unordered_set<int> st;
        for (int i = n - 1; i >= 0; --i) {
            ors.emplace_back(0);
            ors[0] |= nums[i];
            int k = 0;
            for (int j = 1; j < ors.size(); ++j) {
                ors[j] |= nums[i];
                if (ors[k] == ors[j])
                    continue; 
                else ors[++k] = ors[j];
            }
            ors.resize(k + 1);
            for(auto num:ors)
                st.insert(num);
        }
        return st.size();
    }
};
