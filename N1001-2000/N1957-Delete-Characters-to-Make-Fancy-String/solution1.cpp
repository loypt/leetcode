class Solution {
public:
    string makeFancyString(string s) {
        string res;
        for (char ch : s){
            int n = res.size();
            if (n >= 2 && res[n-1] == ch && res[n-2] == ch){
                continue;
            }
            res.push_back(ch);
        }
        return res;
    }
};
