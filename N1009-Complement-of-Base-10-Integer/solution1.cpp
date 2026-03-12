class Solution {
public:
    int bitwiseComplement(int n) {
        int highbit = 0;
        for (int i = 1; i <= 30; ++i) {
            if (n >= (1 << i)) {
                highbit = i;
            }
            else {
                break;
            }            
        }
        int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1);
        return n ^ mask;
    }
};
