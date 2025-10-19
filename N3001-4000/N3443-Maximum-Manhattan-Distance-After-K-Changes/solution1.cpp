class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        char dir[4][2] = {{'N', 'E'}, {'N', 'W'},{'S', 'E'},{'S', 'W'}};
        for(auto d: dir) {
            for(int i = 0, curr = 0, t = k; i < s.size(); ++i){
                if(s[i] == d[0] || s[i] == d[1]){
                    if(t > 0 ) { t--; curr++; }
                    else curr--;
                }else curr++;
                ans = max(ans, curr); 
            }
        }
        return ans;
    }
};
