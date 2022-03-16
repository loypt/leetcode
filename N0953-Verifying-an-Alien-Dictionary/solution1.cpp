class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> cnt(26);
        int i = 0;
        for(const auto& c : order){
            cnt[c - 'a'] = i++;
        }
        for(int i = 0; i < words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];

            bool continueCompare = true;
            for(int k = 0; k < min(s1.size(), s2.size()) && continueCompare; k++){
                if(s1[k] != s2[k]){
                    if(cnt[s1[k]-'a'] > cnt[s2[k]-'a']){
                        return false;
                    }
                    else{
                        continueCompare = false;
                    }
                }
            }
            if(continueCompare && s1.size() > s2.size()){
                return false;
            }
        }
        return true;
    }
};
