class Solution {
public:

    int solve(int x)
    {
        int number = 0;

        while(x > 0)
        {
            int rem = x % 10;
            number += rem;
            x /= 10;
        }

        return number;
    }

    int maximumSum(vector<int>& nums) 
    {
        int n = nums.size();
        priority_queue <pair <int, int>> pq;

        for(int i = 0; i < n; i++)
        {
            int split = solve(nums[i]);
            pq.push({split, nums[i]});
        }

        int maxRes = -1;
        while(pq.size() >= 2)
        {
            int a = pq.top().first;
            int b = pq.top().second;
            pq.pop();

            int c = pq.top().first;
            int d = pq.top().second;
            pq.pop();

            if(a == c)
                maxRes = max(maxRes, b + d);
            else
                pq.push({c, d});    
        }   

        return maxRes;
    }
};