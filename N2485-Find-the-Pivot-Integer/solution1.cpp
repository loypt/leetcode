class Solution 
{
public:
    int pivotInteger(int n) 
    {
        int totsum=0;
        for(int i=1; i<=n; i++)
            totsum += i;
        
        int presum=0;
        
        for(int i=1; i<=n; i++)
        {
            presum += i;
            if((totsum - presum + i) == presum)
                return i;
        }
        return -1;
    }
};
