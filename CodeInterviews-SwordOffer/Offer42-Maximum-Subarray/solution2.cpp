class Solution {
public:
    struct Status{
        int lsum, rsum, msum, isum;
    };
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size()-1).msum;
    }

    Status get(vector<int>& a, int l, int r){
        if(l == r){
            return (Status){a[l], a[l], a[l], a[l]};
        }
        int m = l + r >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m+1, r);
        return pushUp(lSub, rSub);
    }

    Status pushUp(Status l, Status r){
        int iSum = l.isum + r.isum;
        int lSum = max(l.lsum, l.isum+r.lsum);
        int rSum = max(r.rsum, r.isum+l.rsum);
        int mSum = max(max(l.msum, r.msum), l.rsum+r.lsum);
        return (Status){lSum, rSum, mSum, iSum};
    }

    
};
