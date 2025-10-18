class Solution {
public:
    int f(int n, int m) {
        return (m + n / m * m) * (n / m) / 2;
    }

    int sumOfMultiples(int n) {
        return f(n, 3) + f(n, 5) + f(n, 7) - f(n, 3 * 5) - f(n, 3 * 7) - f(n, 5 * 7) + f(n, 3 * 5 * 7);
    }
};
