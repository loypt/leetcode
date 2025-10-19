class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for (string &word : words) {
            stringstream ss(word);
            string sub;
            while (getline(ss, sub, separator)) {
                if (!sub.empty()) {
                    res.push_back(sub);
                }
            }
        }
        return res;
    }
};
