class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        int n=nums.size();
        int t=0;
        for(int i=1;i<k;i++)
        {
            if(nums[i-1]+1==nums[i]) t++;
        }    
        vector<int>ans;
        int j=k,i=1;
        while(j<n)
        {
            if(t==k-1)
            {
                ans.push_back(nums[j-1]);
            }
            else ans.push_back(-1);

            if(nums[i-1]+1==nums[i]) t--;

            if(nums[j-1]+1==nums[j]) t++;
            j++;
            i++;
        }
        if(t==k-1) ans.push_back(nums[n-1]);
        else ans.push_back(-1);
        return ans;
    }
};
