class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (string & info : details) {
            if (stoi(info.substr(11, 2)) > 60) {
                count++;
            }
        }
        return count;
    }
};
