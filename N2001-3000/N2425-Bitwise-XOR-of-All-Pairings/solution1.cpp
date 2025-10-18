class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x1=nums1[0], x2=nums2[0], n1=nums1.size(), n2=nums2.size(), ans=0;
        
        if(n1%2==0 && n2%2==0) return 0;
        for(int i=1;i<n1;i++) x1^=nums1[i];
        for(int i=1;i<n2;i++) x2^=nums2[i];
        
        if(n1&1) ans^=x2;
        if(n2&1) ans^=x1;
        return ans;
    }
};
