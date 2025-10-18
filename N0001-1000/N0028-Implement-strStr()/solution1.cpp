class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if(m == 0){
            return 0;
        }
        vector<int> next(m);
        for(int i = 1, j = 0; i < m; i++){
            while(j > 0 && needle[i] != needle[j]){
                j = next[j-1];
            }
            if(needle[i] == needle[j]){
                j++;
            }
            next[i] = j;
        }
        for(int i = 0, j = 0; i < n; i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j-1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == m){
                return i-m+1;
            }
        }
        return -1;
    }
};
