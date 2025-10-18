class Solution {
public:
    char findTheDifference(string s, string t) {
        int ssum=0, tsum=0;
        for(const auto& c : s){
            ssum += c;
        }
        for(const auto& c: t){
            tsum += c;
        }
        return tsum-ssum;
    }
};
