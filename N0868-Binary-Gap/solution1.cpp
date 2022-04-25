class Solution {
public:
    int binaryGap(int n) {
        int last = -1, res = 0;
        for(int i = 0; n; i++){
            if(n & 1){
                if(last != -1){
                    res = max(res, i - last);
                }
                last = i;
            }
            n >>= 1;
        }
        return res;
    }
};
