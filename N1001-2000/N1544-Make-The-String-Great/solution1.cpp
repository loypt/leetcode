class Solution {
public:
    string makeGood(string s) {
        string ret;
        for (char ch: s) {
            if (!ret.empty() && tolower(ret.back()) == tolower(ch) && ret.back() != ch) {
                ret.pop_back();
            }
            else {
                ret.push_back(ch);
            }
        }
        return ret;
    }
};
