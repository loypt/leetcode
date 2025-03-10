class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();
        int res = 0;
        for (int i = 0; i <= n - k; ++i) {
            int tmp = stoi(s.substr(i, k));
            if (tmp && num % tmp == 0) {
                ++res;
            }
        }
        return res;
    }
};
