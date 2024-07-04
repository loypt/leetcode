class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        for (int y = x; y; y /= 10) {
            s += y % 10;
        }
        return x % s ? -1 : s;
    }
};
