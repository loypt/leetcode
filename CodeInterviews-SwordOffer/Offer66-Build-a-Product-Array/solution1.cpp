class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if(len == 0) return {};
        vector<int> b(len, 1);
        int tmp = 1;
        for(int i = 1; i < len; ++i){
            b[i] = b[i-1]*a[i-1];
        }
        for(int j = len-2; j >= 0; j--){
            tmp *= a[j+1];
            b[j] *= tmp;
        }
        return b;
    }
};
