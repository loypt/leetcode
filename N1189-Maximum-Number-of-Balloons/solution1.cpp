class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(5);
        for (auto & ch : text) {
            if (ch == 'b') {
                cnt[0]++;
            } else if (ch == 'a') {
                cnt[1]++;
            } else if (ch == 'l') {
                cnt[2]++;
            } else if (ch == 'o') {
                cnt[3]++;
            } else if (ch == 'n') {
                cnt[4]++;
            }
        }
        cnt[2] /= 2;
        cnt[3] /= 2;
        return *min_element(cnt.begin(), cnt.end());
    }
};
