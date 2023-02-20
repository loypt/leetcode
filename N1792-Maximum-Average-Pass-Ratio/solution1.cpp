class Solution {
public:
    struct Ratio {
        int pass, total;
        bool operator < (const Ratio& oth) const {
            return (long long) (oth.total + 1) * oth.total * (total - pass) < (long long) (total + 1) * total * (oth.total - oth.pass);
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Ratio> q;
        for (auto &c : classes) {
            q.push({c[0], c[1]});
        }

        for (int i = 0; i < extraStudents; i++) {
            auto [pass, total] = q.top();
            q.pop();
            q.push({pass + 1, total + 1});
        }

        double res = 0;
        for (int i = 0; i < classes.size(); i++) {
            auto [pass, total] = q.top();
            q.pop();
            res += 1.0 * pass / total;
        }
        return res / classes.size();
    }
};
