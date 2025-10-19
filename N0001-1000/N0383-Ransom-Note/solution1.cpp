class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()){
            return false;
        }
        vector<int> cnt(26, 0);
        for(const auto& c : magazine){
            cnt[c-'a']++;
        }
        for(const auto& c : ransomNote){
            cnt[c-'a']--;
            if(cnt[c-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};
