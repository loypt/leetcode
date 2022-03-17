class Solution {
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }
        int modn = 1000000007;
        int p = 0, q = 0, r = 1;
        for(int i = 2; i <= n; i++){
            p = q;
            q = r;
            r = (q+p)%modn;
        }
        return r;
    }
};
