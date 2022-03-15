class Solution {
public:
    string simplifyPath(string path) {
        auto split = [](const string& s, char delimc) -> vector<string> {
            vector<string> strlist;
            string cur = "";
            for(const auto& c: s){
                if(c == delimc){
                    strlist.push_back(move(cur));
                    cur.clear();
                }else{
                    cur += c;
                }
            }
            strlist.push_back(move(cur));
            return strlist;
        };
        vector<string> names = split(path, '/');
        vector<string> stk;
        for(const auto& str: names){
            if(str == ".."){
                if(!stk.empty()){
                    stk.pop_back();
                }
            }else if(!str.empty() && str != "."){
                stk.push_back(move(str));
            }
        }
        string res;
        if(stk.empty()){
            res += "/";
        }else{
            for(const auto& value : stk){
                res += '/' + move(value);
            }
        }
        return res;

    }
};
