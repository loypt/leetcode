struct Event {
    int ts;
    int op;
    int val;
    Event(int _ts, int _op, int _val): ts(_ts), op(_op), val(_val) {}
    bool operator< (const Event& that) const {
        return tie(ts, op) < tie(that.ts, that.op);
    }
};

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<Event> evs;
        for (const auto& event: events) {
            evs.emplace_back(event[0], 0, event[2]);
            evs.emplace_back(event[1], 1, event[2]);
        }
        sort(evs.begin(), evs.end());
        
        int ans = 0, bestFirst = 0;
        for (const auto& [ts, op, val]: evs) {
            if (op == 0) {
                ans = max(ans, val + bestFirst);
            }
            else {
                bestFirst = max(bestFirst, val);
            }
        }
        return ans;
    }
};
