const int MAX_WIDTH = 100;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int width = 0;
        for (auto & c : s) {
            int need = widths[c - 'a'];
            width += need;
            if (width > MAX_WIDTH) {
                lines++;
                width = need;
            }
        }
        return {lines, width};
    }
};
