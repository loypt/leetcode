class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = 0;
        int temp = num2;
        while (temp > 0) {
            if (temp & 1) setBits++;
            temp >>= 1;
        }
        
        int ans = 0;
        
        for (int i = 31; i >= 0 && setBits > 0; --i) {
            if (num1 & (1 << i)) {
                ans |= (1 << i);
                --setBits;
            }
        }
        
        for (int i = 0; setBits > 0; ++i) {
            if ((ans & (1 << i)) == 0) {
                ans |= (1 << i);
                --setBits;
            }
        }
        
        return ans;
    }
};
