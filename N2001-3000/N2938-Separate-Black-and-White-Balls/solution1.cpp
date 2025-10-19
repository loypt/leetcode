class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                sum++;
            } else {
                ans += sum;
            }
        }
        return ans;
    }
};
