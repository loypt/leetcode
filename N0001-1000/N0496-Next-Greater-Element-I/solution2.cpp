class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int, int> mapRightValue;
        stack<int> stk;
        stk.push(nums2[n-1]);
        mapRightValue[nums2[n-1]] = -1;
        for(int i = n-2; i >= 0; i--){
            while(!stk.empty() && nums2[i] > stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                mapRightValue[nums2[i]] = -1;
            }else{
                mapRightValue[nums2[i]] = stk.top();
            }
            stk.push(nums2[i]);
        } 
        vector<int> res(m);
        for(int i = 0; i < m; i++){
            res[i] = mapRightValue[nums1[i]];
        }
        return res;
    }
};
