class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res = {0, 0};
        int i = 0;
        while (n) {
            res[i] += n & 1;
            n >>= 1;
            i ^= 1;
        }
        return res;
    }
};
