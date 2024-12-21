class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        auto check = [&](int m) -> bool {
            vector<int> count0(26);
            for (int j = 0; j < n; j += m) {
                vector<int> count1(26);
                for (int k = j; k < j + m; k++) {
                    count1[s[k] - 'a']++;
                }
                if (j > 0 && count0 != count1) {
                    return false;
                }
                count0.swap(count1);
            }
            return true;
        };
        for (int i = 1; i < n; i++) {
            if (n % i != 0) {
                continue;
            }
            if (check(i)) {
                return i;
            }
        }
        return n;
    }
};
