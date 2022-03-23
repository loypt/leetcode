class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while(k > 0){
            int steps = getStep(curr, n);
            if(steps <= k){
                k -= steps;
                curr++;
            }else{
                curr = curr*10;
                k--;
            }
        }
        return curr;
    }
    
    int getStep(int curr, long n){
        int steps = 0;
        long first = curr;
        long last = curr;
        while(first <= n){
            steps += min(last, n) - first + 1;
            first = first*10;
            last = last*10+9;
        }
        return steps;
    }
};
