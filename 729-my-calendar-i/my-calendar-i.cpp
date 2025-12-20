class MyCalendar {
public:
    vector<pair<int,int>>v;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        bool f = true;
        for(auto p:v){
            if((startTime<p.first && endTime<=p.first) || (startTime>=p.second && endTime>=p.second)){
                continue;
            }
            return false;
        }
        v.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */