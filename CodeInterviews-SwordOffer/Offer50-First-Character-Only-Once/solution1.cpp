class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> charmap;
        for(const auto& c : s){
            charmap[c]++;
        }
        for(const auto& c : s){
            if(charmap[c] == 1){
                return c;
            }
        }
        return ' ';
    }
};
