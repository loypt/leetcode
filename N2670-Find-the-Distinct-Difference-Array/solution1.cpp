class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        vector<int> sufCnt(n + 1, 0);
        for (int i = n - 1; i > 0; i--) {
            st.insert(nums[i]);
            sufCnt[i] = st.size();
        }
        vector<int> res;
        st.clear();
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
            res.push_back(int(st.size()) - sufCnt[i + 1]);
        }
        return res;
    }
}
