class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        
        if (s == goal) {
            vector<int> count(26);
            for (int i = 0; i < s.size(); i++) {
                count[s[i] - 'a']++;
                if (count[s[i] - 'a'] > 1) {
                    return true;
                }
            }
            return false;
        } else {
            int first = -1, second = -1;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != goal[i]) {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else
                        return false;
                }
            }

            return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
        }
    }
};
