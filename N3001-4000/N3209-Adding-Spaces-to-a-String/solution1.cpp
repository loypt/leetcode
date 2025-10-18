class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        string ans;
        ans.reserve(n + spaces.size());
        
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            if (ptr < spaces.size() && spaces[ptr] == i) {
                ans.push_back(' ');
                ++ptr;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
