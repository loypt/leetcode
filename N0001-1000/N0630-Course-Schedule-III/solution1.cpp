class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& c0, const auto& c1){
            return c0[1] < c1[1];
        });

        priority_queue<int> q;
        int total = 0;
        for(const auto& course : courses){
            int t = course[0], d = course[1];
            if(total + t <= d){
                total += t;
                q.push(t);
            }else if(!q.empty() && q.top() > t){
                total -= q.top() - t;
                q.pop();
                q.push(t);
            }
        }
        return q.size();
    }
};
