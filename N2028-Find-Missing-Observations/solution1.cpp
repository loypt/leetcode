class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean*(m+n);
        int missingSum = sum;
        for(const auto& roll : rolls){
            missingSum -= roll;
        }
        if(missingSum < n || missingSum > n*6){
            return {};
        }
        int quotient = missingSum/n, remainder = missingSum %n;
        vector<int> ret(n);
        for(int i = 0; i< n; ++i){
            ret[i] = quotient + (i < remainder ? 1 : 0);
        }
        return ret;
    }
};
