class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; ++i){
            if(isSelfDivding(i)){
                res.push_back(i);
            }
        }
        return res;
    }
    bool isSelfDivding(int num){
        int temp = num;
        while(temp){
            int digit = temp%10;
            if(digit == 0 || num % digit != 0){
                return false;
            }
            temp /= 10;
        }
        return true;
    }
};
