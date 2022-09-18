class Solution {
 public:
     vector<vector<int>> palindromePairs(vector<string>& words) {
         unordered_map<string_view, int> dict;
         vector<vector<int>> ans;
         std::vector<std::string> revesredWords(words.size());
         for(int i = 0; i < words.size(); i++) {
             string key(words[i]);
             reverse(key.begin(), key.end());
             revesredWords[i] = key;
             dict[revesredWords[i]] = i;
         }
         if(dict.find("")!=dict.end()){
             for(int i = 0; i < words.size(); i++){
                 if(i == dict[""]) continue;
                 if(isPalindrome(words[i])) ans.emplace_back(vector<int>{dict[""], i});
             }
         }

         for(int i = 0; i < words.size(); i++) {
             for(int j = 0; j < words[i].size(); j++) {
                 string_view left(words[i].c_str(), j);
                 string_view right(words[i].c_str() + j);
                 if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                     ans.emplace_back(vector<int>{i, dict[left]});
                 }
                 if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                     ans.emplace_back(vector<int>{dict[right], i});
                 }
             }
         }

         return ans;        
     }

     bool isPalindrome(string_view str){
         int i = 0;
         int j = str.size() - 1; 
         while(i < j) {
             if(str[i++] != str[j--]) return false;
         }
         return true;
     }

 };
