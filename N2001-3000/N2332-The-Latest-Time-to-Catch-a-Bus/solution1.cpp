class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int pos = 0;
        int space = 0;
        for (int arrive : buses) {
            space = capacity;
            while (space > 0 && pos < passengers.size() && passengers[pos] <= arrive) {
                space--;
                pos++;
            }
        }
        
        pos--;
        int lastCatchTime = space > 0 ? buses.back() : passengers[pos];
        while (pos >= 0 && passengers[pos] == lastCatchTime) {
            pos--;
            lastCatchTime--;
        }

        return lastCatchTime;
    }
};
