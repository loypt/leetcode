class Solution {
    bool check(string t,string s){
        int lenx = (int)s.length() / (int)t.length();
        string ans = "";
        for (int i = 1; i <= lenx; ++i){
            ans = ans + t;
        }
        return ans == s;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = (int)str1.length(), len2 = (int)str2.length();
        for (int i = min(len1, len2); i >= 1; --i){ // 从长度大的开始枚举
            if (len1 % i == 0 && len2 % i == 0){
                string X = str1.substr(0, i);
                if (check(X, str1) && check(X, str2)) return X;
            }
        }
        return "";
    }
};
