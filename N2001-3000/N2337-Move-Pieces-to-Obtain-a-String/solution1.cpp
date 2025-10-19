class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == '_') {
                i++;
            }
            while (j < n && target[j] == '_') {
                j++;
            }
            if (i < n && j < n) {
                if (start[i] != target[j]) {
                    return false;
                }
                char c = start[i];
                if ((c == 'L' && i < j) || (c == 'R' && i > j)) {
                    return false;
                }
                i++;
                j++;
            }
        }
        while (i < n) {
            if (start[i] != '_') {
                return false;
            }
            i++;
        }
        while (j < n) {
            if (target[j] != '_') {
                return false;
            }
            j++;
        }
        return true;
    }
};
