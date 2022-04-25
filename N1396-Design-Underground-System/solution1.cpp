class UndergroundSystem {
public:
    using Start = pair<string ,int>;
    using StartEnd = pair<string, string>;
    using sumAndAmount = pair<int, int>;

    struct StartEndHash {
        int operator() (const StartEnd& x)const{
            return hash<string>() (x.first + x.second);
        }
    };

    unordered_map<int, Start> startInfo;
    unordered_map<StartEnd, sumAndAmount, StartEndHash> table;

    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        startInfo[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto startTime = startInfo[id].second;
        table[{startInfo[id].first, stationName}].first += t - startTime;
        table[{startInfo[id].first, stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto sum = table[{startStation, endStation}].first;
        auto amount = table[{startStation, endStation}].second;
        return double(sum) / amount;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
