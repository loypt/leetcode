class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin() ,endTime.end());
		
        int u = upper_bound(startTime.begin(), startTime.end(), queryTime) - startTime.begin();
		
        int l = lower_bound(endTime.begin(), endTime.end(), queryTime) - endTime.begin();
		
        return u - l;
    }
};
