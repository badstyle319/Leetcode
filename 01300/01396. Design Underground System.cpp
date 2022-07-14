class UndergroundSystem {
    map<int,pair<string,int>> login;
    map<pair<string,string>,vector<int>> time;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        login[id] = make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p = make_pair(login[id].first, stationName);
        if(!time.count(p))
            time[p] = vector<int>();
        time[p].push_back(t-login[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto p = make_pair(startStation, endStation);
        double avg = 0;
        if(time[p].size() == 0)
            return avg;
        for(auto n:time[p])
            avg += n;
        avg /= time[p].size();
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */