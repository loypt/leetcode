class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int m = s.size();
        vector<vector<int>> f(m+1, vector<int>(26));
        for(int j = 0; j < 26; j++){
            f[m][j] = m;
        }
        for(int i = m-1; i >= 0; --i){
            for(int j = 0; j < 26; ++j){
                if(s[i] == 'a'+j){
                    f[i][j] = i;
                }else{
                    f[i][j] = f[i+1][j];
                }
            }
        }

        string res = "";
        for(const auto& t : dictionary){
            bool match = true;
            int j = 0;
            for(int i = 0; i < t.size(); ++i){
                if(f[j][t[i]-'a'] == m){
                    match = false;
                    break;
                }
                j = f[j][t[i]-'a']+1;
            }
            if(match){
                if(t.size() > res.size() || (t.size() == res.size() && t.compare(res) < 0)){
                    res = t;
                }
            }
        }
        return res;
    }
};
