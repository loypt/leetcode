class Solution {
public:
    long long countFairPairs(vector<int>& v, int first_val, int last_val) {
        deque<int>vc;
        sort(v.begin(),v.end());
        for(auto i:v) vc.push_back(i);
        long long int ans=0;
        for(int i=0;i<v.size();i++)
        {
            vc.pop_front();
            int lower=first_val-v[i],upper=last_val-v[i];
            auto left=lower_bound(vc.begin(),vc.end(),lower);
            auto right=upper_bound(vc.begin(),vc.end(),upper);
            ans+=(right-left);
        }
        return ans;
    }
};
