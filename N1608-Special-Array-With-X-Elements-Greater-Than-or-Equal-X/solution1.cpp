class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size(), curMax = 0;
        int counter[101];
        memset(counter, 0, sizeof(counter));
        
        for(auto n : nums) {
            curMax = max(curMax, n);
            counter[n > 100 ? 100 : n]++;
        }
        int cur = 0;
        curMax = (curMax > 100 ? 100 : curMax);
        for(int i = curMax; i >= 1; --i) {
            if(counter[i] != 0) cur += counter[i];
            if(cur == i) return cur;
        }   
        return -1;
    }
};
