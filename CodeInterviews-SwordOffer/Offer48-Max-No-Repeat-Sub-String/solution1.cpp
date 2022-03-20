class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        unordered_map<char, int> mp;
        
        int maxLength = 0, preLength = 1, curLength;
        
        for(int i = 0; i < n; i++){
            if(mp.count(s[i]) == 1){
                curLength = min(preLength, i-mp[s[i]]-1)+1;
            }else{
                curLength = min(preLength, i)+1;
            }
            mp[s[i]] = i;
            maxLength = max(maxLength, curLength);
            preLength = curLength;
        }
        return maxLength;
    }
};
