class Solution {
public:
    int cuttingRope(int n) {
        int mk = 1000000007;
        if(n < 4){
            return n-1;
        }
        int b = n % 3;
        long rem = 1, x = 3;
        for(int a = n/3-1; a > 0; a /= 2){
            if(a % 2 == 1) rem = (rem * x) % mk;
            x = (x * x) % mk;
        }
        if(b == 0) return (int)(rem * 3 % mk);
        if(b == 1) return (int)(rem * 4 % mk);
        return (int)(rem * 6 % mk);
    }
};
