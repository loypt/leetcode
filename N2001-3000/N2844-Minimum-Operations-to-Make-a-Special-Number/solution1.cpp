class Solution {
public:
    int minimumOperations(string num) {
        int n = num.length();
        bool find0 = false, find5 = false;
        for (int i = n - 1; i >= 0; --i) {
            if (num[i] == '0' || num[i] == '5') {
                if (find0) {
                    return n - i - 2;
                }
                if (num[i] == '0') {
                    find0 = true;
                } else {
                    find5 = true;
                }
            } else if (num[i] == '2' || num[i] == '7') {
                if (find5) {
                    return n - i - 2;
                }
            }
        }
        if (find0) {
            return n - 1;
        }
        return n;
    }
};
