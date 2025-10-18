class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n == 1){
            return 1;
        }
        return (k + findTheWinner(n-1, k)-1)%n+1;
    }
};
