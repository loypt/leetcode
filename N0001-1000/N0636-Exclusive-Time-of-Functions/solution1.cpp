class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> st; // id, start time
        vector<int> res(n, 0);
        for (auto& log : logs) {
            char type[10];
            int idx, timestamp;
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp); // format string
            if (type[0] == 's') {
                if (!st.empty()) {
                    res[st.top().first] += timestamp - st.top().second;
                    st.top().second = timestamp;
                }
                st.emplace(idx, timestamp);
            } else {
                auto t = st.top();
                st.pop();
                res[t.first] += timestamp - t.second + 1;
                if (!st.empty()) {
                    st.top().second = timestamp + 1;
                }
            }
        }
        return res;
    }
};
