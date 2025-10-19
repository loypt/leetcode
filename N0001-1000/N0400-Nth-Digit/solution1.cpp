class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        long start = 1;
        long count = 9;
        while(n > count){
            n -= count;
            digit++;
            start *= 10;
            count = digit * start * 9;
        }
        int num=start+(n-1)/digit;
        count=(n-1)%digit;     //计算是该数字第几位
        string s=to_string(num);
        int ans=s[count]-'0';
        return ans;
    }
};
