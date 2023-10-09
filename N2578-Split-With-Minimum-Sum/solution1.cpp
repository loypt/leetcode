class Solution {
public:
    int splitNum(int num) {
        string stnum = to_string(num);
        sort(stnum.begin(), stnum.end());
        int num1 = 0, num2 = 0;
        for (int i = 0; i < stnum.size(); ++i) {
            if (i % 2 == 0) {
                num1 = num1 * 10 + (stnum[i] - '0');
            }
            else {
                num2 = num2 * 10 + (stnum[i] - '0');
            }
        }
        return num1 + num2;
    }
};
