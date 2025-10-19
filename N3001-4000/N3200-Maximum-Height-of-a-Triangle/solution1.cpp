class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        auto maxHeight = [](int x, int y) -> int {
            for (int i = 1;; ++i) {
                if (i % 2 == 1) {
                    x -= i;
                    if (x < 0) {
                        return i - 1;
                    }
                }
                else {
                    y -= i;
                    if (y < 0) {
                        return i - 1;
                    }
                }
            }
        };
        return max(maxHeight(red, blue), maxHeight(blue, red));
    }
};
