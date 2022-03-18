class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0){
            return 0;
        }
        vector<int> leftmax(n);
        leftmax[0] = height[0];
        for(int i = 1; i < n; i++){
            leftmax[i] = max(leftmax[i-1], height[i]);
        }

        vector<int> rightmax(n);
        rightmax[n-1] = height[n-1];
        for(int j= n-2; j >= 0; j--){
            rightmax[j] = max(rightmax[j+1], height[j]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += min(leftmax[i], rightmax[i])-height[i];
        }
        return ans;
    }
};
