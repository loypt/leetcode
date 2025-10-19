class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastMoment = 0;
        for (int ant : left) {
            lastMoment = max(lastMoment, ant);
        }
        for (int ant : right) {
            lastMoment = max(lastMoment, n - ant);
        }
        return lastMoment;
    }
};
