class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            int j = 0;
            while(nums2[j] != nums1[i] && j < nums2.size()){
                j++;
            }
            while(nums2[j] <= nums1[i] && j< nums2.size()-1){
                j++;
            }
            if(nums1[i] < nums2[j]){
                res[i] = nums2[j];
            }else{
                res[i] = -1;
            }
        }
        return res;
    }
};
