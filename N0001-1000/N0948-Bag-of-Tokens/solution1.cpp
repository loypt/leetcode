class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int lo = 0, hi = tokens.size() - 1;
        int points = 0, ans = 0;
        while(lo <= hi && (power >= tokens[lo] || points > 0)){
            while(lo <= hi && power >= tokens[lo]){
                power -= tokens[lo++];
                points++;
            }
            
            ans = max(ans, points);
            if(lo <= hi && points > 0){
                power += tokens[hi--];
                points--;
            }
        }
        return ans;
    }
};
