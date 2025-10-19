class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        for (int i = 1; i < hours.size(); i++) {
            for (int j = 0; j < i; j++) {
                if ((hours[i] + hours[j]) % 24 == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
