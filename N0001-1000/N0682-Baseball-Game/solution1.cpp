class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ret = 0;
        vector<int> points;
        for(auto &op : ops){
            int n  = points.size();
            switch(op[0]){
                case '+':
                    ret += points[n-1] + points[n-2];
                    points.push_back(points[n-1]+points[n-2]);
                    break;
                case 'D':
                    ret += points[n-1] * 2;
                    points.push_back(2*points[n-1]);
                    break;
                case 'C':
                    ret -= points[n-1];
                    points.pop_back();
                    break;
                default : 
                    ret += stoi(op);
                    points.push_back(stoi(op));
                    break;
            }
        }
        return ret;
    }
};
