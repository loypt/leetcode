class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n-1;
        for(auto num : nums){
            if(num % 2 == 0){
                res[left++] = num;
            }else{
                res[right--] = num;
            }
        }
        return res;
    }
};
