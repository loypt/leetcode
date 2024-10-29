class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        string str;

        function<void(string &)> dfs = [&](string& str) {
            if (str.size() == n) {
                res.push_back(str);
                return;
            }
            if (str.empty() || str.back() == '1') {
                str.push_back('0');
                dfs(str);
                str.pop_back();
            }
            str.push_back('1');
            dfs(str);
            str.pop_back();
        };
        
        dfs(str);
        return res;
    }
};
