class Solution {
public:
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            int dis = min(s[i] - 'a', 'z' - s[i] + 1);
            if (dis <= k) {
                s[i] = 'a';
                k -= dis;
            }
            else {
                s[i] -= k;
                break;
            }
        }
        return s;
    }
};
