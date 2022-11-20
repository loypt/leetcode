class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, sum = 0;
        for (int x: gain) {
            sum += x;
            ans = max(ans, sum);
        }
        return ans;
    }
};
