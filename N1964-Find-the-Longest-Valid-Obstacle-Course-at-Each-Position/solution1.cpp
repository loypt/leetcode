class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> d, ans;
        for (int ob: obstacles) {
            if (d.empty() || ob >= d.back()) {
                d.push_back(ob);
                ans.push_back(d.size());
            }
            else {
                int loc = upper_bound(d.begin(), d.end(), ob) - d.begin();
                ans.push_back(loc + 1);
                d[loc] = ob;
            }
        }
        return ans;
    }
};
