class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c == ',') {
                continue;
            } else if (c != ')') {
                stk.push(c);
            } else {
                int t = 0, f = 0;
                while (stk.top() != '(') {
                    char val = stk.top();
                    stk.pop();
                    if (val == 't') {
                        t++;
                    } else {
                        f++;
                    }
                }
                stk.pop();
                char op = stk.top();
                stk.pop();
                switch (op) {
                case '!':
                    stk.push(f == 1 ? 't' : 'f');
                    break;
                case '&':
                    stk.push(f == 0 ? 't' : 'f');
                    break;
                case '|':
                    stk.push(t > 0 ? 't' : 'f');
                    break;
                default:
                    break;
                }
            }
        }
        return stk.top() == 't';
    }
};
