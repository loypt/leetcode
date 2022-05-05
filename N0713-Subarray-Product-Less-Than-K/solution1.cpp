class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0){
            return 0;
        }
        int n = nums.size();
        vector<double> logPrefix(n + 1);
        for(int i = 0; i < n; i++){
            logPrefix[i+1] = logPrefix[i]+log(nums[i]);
        }
        double logk = log(k);
        int ret = 0;
        for(int j = 0; j < n; j++){
            int l = upper_bound(logPrefix.begin(), logPrefix.begin() + j + 1, logPrefix[j + 1] - log(k) + 1e-10) - logPrefix.begin();
            ret += j + 1 - l;
        }
        return ret;
    }
};
