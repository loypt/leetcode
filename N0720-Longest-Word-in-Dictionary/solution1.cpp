class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b){
            if(a.size() != b.size()){
                return a.size() < b.size();
            }else{
                return a > b;
            }
        });
        string longest = "";
        unordered_set<string> cnt;
        cnt.emplace("");
        for(const auto& word : words){
            if(cnt.count(word.substr(0, word.size()-1))){
                cnt.emplace(word);
                longest = word;
            }
        }
        return longest;
    }
};
