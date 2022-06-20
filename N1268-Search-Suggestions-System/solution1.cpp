class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto it = products.begin();
        sort(it, products.end());
        vector<vector<string>> res;
        string cur = "";
        for(char c : searchWord){
            cur += c;
            vector<string> suggested;
            it = lower_bound(it, products.end(), cur);
            for(int i = 0; i < 3 && it+i != products.end(); i++){
                string& s = *(it+i);
                if(s.find(cur)) break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
};
