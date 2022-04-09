class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(0, nums.size()-1, nums, tmp);
    }

    int mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp){
        if(l >= r) return 0;

        int m = (l+r)/2;
        int res = mergeSort(l, m, nums, tmp) + mergeSort(m+1, r, nums, tmp);

        int i = l, j = m + 1;
        for(int k = l; k <= r; ++k){
            tmp[k] = nums[k];
        }
        for(int k = l; k <= r; k++){
            if(i == m+1){
                nums[k] = tmp[j++];
            }else if(j == r+1 || tmp[i] <= tmp[j]){
                nums[k] = tmp[i++];
            }else{
                nums[k] = tmp[j++];
                res += m -i +1;
            }
        }
        return res;
    }
};
