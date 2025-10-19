class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        string s;
        for(int i = 0; i < len1 || i < len2; i++){
            if(i < len1) s+=word1[i];
            if(i< len2) s+= word2[i]; 
        }
        return s;
    }
};
