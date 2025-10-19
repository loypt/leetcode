class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int num=0;
        for (auto x:grid){
            int l=0,r=(int)x.size()-1,pos=-1;
            while (l<=r){
                int mid=l+((r-l)>>1);
                if (x[mid]<0){
                    pos=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if (~pos) num+=(int)x.size()-pos;
        }
        return num;
    }
};
