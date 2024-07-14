class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0, n = formula.length();

        auto parseAtom = [&]() -> string {
            string atom;
            atom += formula[i++];
            while (i < n && islower(formula[i])) {
                atom += formula[i++];
            }
            return atom;
        };

        auto parseNum = [&]() -> int {
            if (i == n || !isdigit(formula[i])) {
                return 1;
            }
            int num = 0;
            while (i < n && isdigit(formula[i])) {
                num = num * 10 + int(formula[i++] - '0');
            }
            return num;
        };

        stack<unordered_map<string, int>> stk;
        stk.push({});
        while (i < n) {
            char ch = formula[i];
            if (ch == '(') {
                i++;
                stk.push({});
            } else if (ch == ')') {
                i++;
                int num = parseNum();
                auto atomNum = stk.top();
                stk.pop();
                for (auto &[atom, v] : atomNum) {
                    stk.top()[atom] += v * num;
                }
            } else {
                string atom = parseAtom();
                int num = parseNum();
                stk.top()[atom] += num;
            }
        }

        auto &atomNum = stk.top();
        vector<pair<string, int>> pairs;
        for (auto &[atom, v] : atomNum) {
            pairs.emplace_back(atom, v);
        }
        sort(pairs.begin(), pairs.end());

        string ans;
        for (auto &p : pairs) {
            ans += p.first;
            if (p.second > 1) {
                ans += to_string(p.second);
            }
        }
        return ans;
    }
};
