class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for(int i = n; i >= 1; --i){
            int bound = k - 26*(i-1);
            if(bound > 0){
                ans += char(bound + 'a' - 1);
                k -= bound;
            }else{
                ans += 'a';
                k -= 1;
            }
        }
        return ans;
    }
};
