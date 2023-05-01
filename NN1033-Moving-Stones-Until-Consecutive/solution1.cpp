class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min({a, b, c});
        int z = max({a, b, c});
        int y = a + b + c - x - z;

        vector<int> res(2);
        res[0] = 2;
        if ((z - y) == 1 && (y - x) == 1) {
            res[0] = 0;
        } else if ((z - y) <= 2 || (y - x) <= 2) {
            res[0] = 1;
        }
        res[1] = (z - x - 2);
        return res;
    }
};
