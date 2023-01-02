class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> seen;
        for (char ch: s) {
            if (seen.count(ch)) {
                return ch;
            }
            seen.insert(ch);
        }
        return ' ';
    }
};
