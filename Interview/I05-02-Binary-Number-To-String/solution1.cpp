class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        while (res.size() <= 32 && num != 0) {
            num *= 2;
            int digit = num;
            res.push_back(digit + '0');
            num -= digit;
        }
        return res.size() <= 32 ? res : "ERROR";
    }
};
