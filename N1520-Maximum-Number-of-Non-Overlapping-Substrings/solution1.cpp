class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, pair<int, int>> pos;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (pos.find(ch) == pos.end()) {
                pos[ch] = {i, i};
            } else {
                pos[ch].second = i;
            }
        }
        
        vector<pair<int, int>> valid;
        
        for (auto& [c, range] : pos) {
            int l = range.first, r = range.second;
            int nl = l, nr = l;
            
            while (nl >= l || nr <= r) {
                int i = (nl >= l) ? nl : nr;
                
                int l_t = pos[s[i]].first;
                int r_t = pos[s[i]].second;
                
                if (l_t < l) {
                    l = l_t;
                }
                
                if (r_t > r) {
                    r = r_t;
                }
                
                if (i == nl) {
                    nl--;
                }
                
                if (i == nr) {
                    nr++;
                }
            }
            
            valid.push_back({l, r});
        }
        
        sort(valid.begin(), valid.end(), 
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });
        
        vector<string> ans;
        int end = -1;
        
        for (auto& [left, right] : valid) {
            if (left > end) {
                ans.push_back(s.substr(left, right - left + 1));
                end = right;
            }
        }
        
        return ans;
    }
};
