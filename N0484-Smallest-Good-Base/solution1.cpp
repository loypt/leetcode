class Solution {
public:
    string smallestGoodBase(string n) {
        long num = stol(n);
        int maxM = floor(log(num)/ log(2));
        for(int i = maxM; i > 1; i--){
            int k = pow(num, 1.0/i);
            long mul = 1, sum = 1;{
                for(int j= 0; j < i; j++){
                    mul *= k;
                    sum += mul;  
                }
                if(sum == num){
                    return to_string(k);
                }
            }
        }
        return to_string(num-1);
    }
};
