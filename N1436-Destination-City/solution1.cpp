class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        unordered_set<string> citiesA;
        for (auto &path : paths) {
            citiesA.insert(path[0]);
        }
        for (auto &path : paths) {
            if (!citiesA.count(path[1])) {
                return path[1];
            }
        }
        return "";
    }
};
