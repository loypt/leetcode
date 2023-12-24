class Solution {
public:
    bool isPathCrossing(string path) {
        auto pairHash = [](const pair<int, int>& o) {
            return o.first * 20001 + o.second;
        };
        unordered_set<pair<int, int>, decltype(pairHash)> vis(0, pairHash);

        int x = 0, y = 0;
        vis.emplace(x, y);

        for (char dir: path) {
            switch (dir) {
                case 'N': --x; break;
                case 'S': ++x; break;
                case 'W': --y; break;
                case 'E': ++y; break;
            }
            if (vis.find({x, y}) != vis.end()) {
                return true;
            } else {
                vis.emplace(x, y);
            }
        }

        return false;
    }
};
