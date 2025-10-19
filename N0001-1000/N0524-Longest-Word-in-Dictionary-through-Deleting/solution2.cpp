class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string word1, string word2){
            if(word1.size() != word2.size()){
                return word1.size() > word2.size();
            }else{
                return word1.compare(word2) < 0;
            }
        });
        for(const auto& t : dictionary){
            int i = 0, j = 0;
            while(i < s.size() && j < t.size()){
                if(s[i] == t[j]){
                    j++;
                }
                i++;
            }
            if(j == t.size()){
                return t;
            }
        }
        return "";
    }
};
