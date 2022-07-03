class Solution {
public:
    using ll = long long;
    static constexpr int mod = 1e9 +7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int resHeight=0, resWidth=0;
        int pre=0;
        for(auto i : horizontalCuts){
            resHeight = max(resHeight,i-pre);
            pre=i;
        }
        resHeight = max(resHeight,h-pre);   // 比较当前高度与下边界的距离
        pre=0;
        for(auto  i : verticalCuts){
            resWidth = max(resWidth,i-pre);
            pre=i;
        }
        resWidth=max(resWidth,w-pre);
        
        return ((ll)resHeight*resWidth) % mod;
    }
};
