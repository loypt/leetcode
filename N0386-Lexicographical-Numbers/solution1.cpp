class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int number = 1;
        for(int i = 0; i < n; i++){
            ret[i] = number;
            if(number*10 <= n){
                number *= 10;
            }else{
                while(number%10 == 9 || number+1 > n){
                    number/=10;
                }
                number++;
            }
        }
        return ret;
    }
};
