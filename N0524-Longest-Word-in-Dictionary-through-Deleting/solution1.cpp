class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for(const auto& t : dictionary){
            int i = 0,j = 0;
            while(i < s.size() && j < s.size()){
                if(s[i] == t[j]){
                    j++;
                }
                i++;
            }
            if(j == t.size()){
                if(t.size() > res.size() || (t.size() == res.size() && t.compare(res) < 0)){
                    res = t;
                }
            }
        }
        return res;
    }
};
