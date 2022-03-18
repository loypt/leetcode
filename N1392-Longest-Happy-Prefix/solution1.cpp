class Solution {
public:
    string longestPrefix(string s) {
        vector<int> next(s.size());
        for(int i = 1, j = 0; i < s.size(); i++){
            while(j > 0 && s[i] != s[j]){
                j = next[j-1];
            }
            if(s[i] == s[j]){
                j++;
            }
            next[i] = j;
        }
        return s.substr(0, next[s.size()-1]);
    }
};
