class Solution {
public:
    int maxFrequencyElements(vector<int> &nums) {
        int ans = 0, maxCnt = 0;
        unordered_map<int, int> cnt;
        for (int x : nums) {
            int c = ++cnt[x];
            if (c > maxCnt) {
                maxCnt = ans = c;
            } else if (c == maxCnt) {
                ans += c;
            }
        }
        return ans;
    }
};
