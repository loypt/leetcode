class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n = s.size();
        if(n == 0) return res;
        int right = n-1;
        while(right >= 0){
            while(right >= 0 && s[right] == ' ') right--;
            if(right < 0) break;

            int left = right;
            while(left >= 0 && s[left] != ' ') left--;

            res+=s.substr(left+1, right - left);
            res += ' ';

            right = left;
        }
        if(!res.empty()) res.pop_back();
        return res;
    }
};
