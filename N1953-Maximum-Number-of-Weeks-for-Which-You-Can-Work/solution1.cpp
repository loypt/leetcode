class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long longest = *max_element(milestones.begin(), milestones.end());
        long long rest = accumulate(milestones.begin(), milestones.end(), 0LL) - longest;
        if (longest > rest + 1){
            return rest * 2 + 1;
        }
        else {
            return longest + rest;
        }
    }
};
