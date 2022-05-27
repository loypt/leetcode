class Solution {
public:
    int numberOfSteps(int num) {
        int ret = 0;
        while (num) {
            ret += (num > 1 ? 1 : 0) + (num & 0x01);
            num >>= 1;
        }
        return ret;
    }
};
