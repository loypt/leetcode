class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.top().first < nums[i]) {
                res[q.top().second] = nums[i];
                q.pop();
            }
            while (!st.empty() && nums[st.top()] < nums[i]) {
                q.push({nums[st.top()], st.top()});
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
