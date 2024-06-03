class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        int p = (int)(sqrt(2 * candies + 0.25) - 0.5);
        int remaining = (int)(candies - (p + 1) * p * 0.5);
        int rows = p / n, cols = p % n;

        vector<int> d(n, 0);
        for (int i = 0; i < n; ++i) {
            d[i] = (i + 1) * rows + (int)(rows * (rows - 1) * 0.5) * n;
            if (i < cols) {
                d[i] += i + 1 + rows * n;
            }
        }
        d[cols] += remaining;
        return d;
    }
};
