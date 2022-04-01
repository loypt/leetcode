class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for(int num : nums){
            ret ^= num;
        }
        int div = 1;
        while((div & ret) == 0){
            div <<= 1;
        }
        int a = 0, b = 0;
        for(int num : nums){
            if(div & num){
                a ^= num;
            }else{
                b ^= num;
            }
        }
        return vector<int>{a, b};
    }
};
