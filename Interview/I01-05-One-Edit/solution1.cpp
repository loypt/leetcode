class Solution {
public:
    bool oneEditAway(string first, string second) {
        int p1 = 0;
        int q1 = first.size() - 1;
        int p2 = 0;
        int q2 = second.size() - 1;
        while (p1 <= q1 && p2 <= q2) {
            if (first[p1] == second[p1]) {
                ++p1;
                ++p2;
                continue;
            }
            if (first[q1] == second[q2]) {
                --q1;
                --q2;
            } else {
                break;
            }
        }
        return q1 - p1 + q2 - p2 <= 0 && abs(p1 - p2) <= 1 && abs(q1 - q2) <= 1;
    }
};
