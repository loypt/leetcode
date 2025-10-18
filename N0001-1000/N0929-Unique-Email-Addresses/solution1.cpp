regex r("(?:\\.)(?=.*@)|(?:\\+.*)(?=@)"); 
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> dict;
        for (auto& i : emails) dict.insert(regex_replace(i, r, ""));
        return dict.size();
    }
};
