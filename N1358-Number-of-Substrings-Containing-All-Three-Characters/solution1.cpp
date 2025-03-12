class Solution {
    #define N 50010
    int pre[3][N];
public:
    int numberOfSubstrings(string s) {
        int len=(int)s.length(),ans=0;
        pre[0][0]=pre[1][0]=pre[2][0]=0;
        for (int i=0;i<(int)s.length();++i){
            for (int j=0;j<3;++j) pre[j][i+1]=pre[j][i];
            pre[s[i]-'a'][i+1]++;
        }
        for (int i=0;i<len;++i){
            int l=i+1,r=len,pos=-1;
            while (l<=r){
                int mid=l+((r-l)>>1);
                if (pre[0][mid]-pre[0][i]>0 && pre[1][mid]-pre[1][i]>0 && pre[2][mid]-pre[2][i]>0){
                    r=mid-1;
                    pos=mid;
                }
                else l=mid+1;
            }
            if (~pos) ans+=len-pos+1;
        }
        return ans;
    }
};
