class Solution {
public:
    bool isBalanced(string num) {
        int diff = 0, sign = 1;
        for (char c : num) {
            int d = c - '0';
            diff += d * sign;
            sign = -sign;
        }
        return diff == 0;
    }
};
