class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> ans(nums.size(), 0);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        for(auto i = 0; i < nums.size(); ++i) pq.push({nums[i], i});
        for(int i = 0; i < k; ++i){
            auto [num, ind] = pq.top();
            pq.pop();
            pq.push({num * multiplier, ind});
        }
        while(pq.size()){
            ans[pq.top().second] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};
