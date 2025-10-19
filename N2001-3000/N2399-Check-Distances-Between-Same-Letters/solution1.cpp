class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j] && distance[s[i] - 'a'] != j - i - 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
