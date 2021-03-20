class UndergroundSystem {
public:
    map<int, pair<int, string>> start;
    map<vector<string>, double> time;
    map<vector<string>, int> count;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        pair<int, string> customerStart = make_pair(t, stationName);
        start[id] = customerStart;
    }
    
    void checkOut(int id, string stationName, int t) {
        vector<string> travelLoc = {start[id].second, stationName};
        time[travelLoc] += (double) (t - start[id].first);
        count[travelLoc] += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<string> travelLoc = {startStation, endStation};
        return (double) time[travelLoc] / count[travelLoc];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */