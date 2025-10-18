class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int x = left; x <= right; ++x){
            if(isPrime(__builtin_popcount(x))){
                ++ans;
            }
        }
        return ans;
    }

    bool isPrime(int x){
        if(x < 2){
            return false;
        }
        for(int i  = 2; i * i <= x; ++i){
            if(x % i == 0){
                return false; 
            }
        }
        return true; 
    }
};
