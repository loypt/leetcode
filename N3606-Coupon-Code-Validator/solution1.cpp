class Solution {
public:
    bool check(string code, bool isActive) {
        for (auto it : code) {
            if (it != '_' && !isalnum(it)) {
                return false;
            }
        }
        return isActive;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<string> groups[4];
        vector<string> ans;
        for (int i = 0; i < code.size(); i++) {
            if (code[i].size() && check(code[i], isActive[i])) {
                if (businessLine[i] == "electronics") {
                    groups[0].push_back(code[i]);
                } else if (businessLine[i] == "grocery") {
                    groups[1].push_back(code[i]);
                } else if (businessLine[i] == "pharmacy") {
                    groups[2].push_back(code[i]);
                } else if (businessLine[i] == "restaurant") {
                    groups[3].push_back(code[i]);
                }
            }
        }
        for (auto& group : groups) {
            sort(group.begin(), group.end());
            ans.insert(ans.end(), group.begin(), group.end());
        }
        return ans;
    }
};
