class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans =0;
        int n =nums.size();
        map<int,int> mp;
        for (int i=0;i<n;i++){
            if (mp.find(nums[i]-i)!=mp.end()){
                ans-=mp[nums[i]-i];
            }
            ans +=i;
            mp[nums[i]-i]++;
        }
        return ans;
    }
};
