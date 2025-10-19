const static string MORSE[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
        "...-", ".--", "-..-", "-.--", "--.."
};
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> wordSet;
        for(auto& word : words){
            string code;
            for(auto& c : word){
                code.append(MORSE[c-'a']);
            }
            wordSet.emplace(code);
        }
        return wordSet.size();
    }
};
