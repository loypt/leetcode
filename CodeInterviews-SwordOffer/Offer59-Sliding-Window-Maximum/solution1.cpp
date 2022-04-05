class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0 || k == 0){
            return vector<int> {};
        }
        priority_queue<pair<int, int>> que;
        for(int i = 0; i < k; ++i){
            que.emplace(nums[i], i);
        }
        vector<int> resArray = {que.top().first};
        for(int j = k; j < len; ++j){
            que.emplace(nums[j], j);
            while(que.top().second <= j-k){
                que.pop();
            }
            resArray.push_back(que.top().first);
        }
        return resArray;
    }
};
