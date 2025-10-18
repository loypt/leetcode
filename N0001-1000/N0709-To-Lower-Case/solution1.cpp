class Solution {
public:
    string toLowerCase(string s) {
        for(char& c : s){
            if(c >= 65 && c <= 90){
                c |= 32;
            }
        }
        return s;
    }
};
