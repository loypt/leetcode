class Solution {
public:
    int solve(int i,int n,int k,vector<int> &nums,vector<int> &mums){
        if(k==mums.size()){
            return 0;
        }
        if(dp[i][k]!=INT_MIN)return dp[i][k];
        return dp[i][k]=max(solve(i+1,n,k+1,nums,mums)+(nums[i]*mums[k]),
        solve(i,n,k+1,nums,mums)+(nums[(n-1)-(k-i)]*mums[k]));
    }
    int maximumScore(vector<int>& nums, vector<int>& mums) {
        int n=nums.size(), m=mums.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return solve(0,n,0,nums,mums);
    }
private:
    vector<vector<int>> dp;
};
