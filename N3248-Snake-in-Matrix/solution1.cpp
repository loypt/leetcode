class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans = 0;
        for (const string& c: commands) {
            if (c[0] == 'U') {
                ans -= n;
            }
            else if (c[0] == 'D') {
                ans += n;
            }
            else if (c[0] == 'L') {
                --ans;
            }
            else {
                ++ans;
            }
        }
        return ans;
    }
};
