class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        int len = part.size();

        for(char c : s){
            result.push_back(c);
            if(result.size()>=len && result.substr(result.length() -len)==part){
                result.erase(result.length()-len);
            }
        }
    return result;
        
    }
};
