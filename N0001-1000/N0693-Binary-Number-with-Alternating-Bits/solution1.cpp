class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = 2;
        while(n != 0){
            int cur = n %2;
            if(cur == prev){
                return false;
            }
            prev = cur;
            n /= 2;
        }
        return true;
    }
};
