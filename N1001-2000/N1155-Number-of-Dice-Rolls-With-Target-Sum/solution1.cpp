class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> ways(target + 1);
        ways[0] = 1;
        int mod = pow(10, 9) + 7;
        for (int x=1;x<=d;x++) {
            for (int i = target; i >= 0; i--) {
                int way = 0;
                for (int y = i - 1; y >= max(0, i - f);  y--) way = (way + ways[y]) % mod;
                ways[i] = way;
            }
        }
        return ways[target];
    }
};
