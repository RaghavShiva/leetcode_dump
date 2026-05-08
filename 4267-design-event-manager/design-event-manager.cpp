class EventManager {
public:
    priority_queue<pair<int,int>>pq;
    map<int,int>m;
    EventManager(vector<vector<int>>& events) {
        for(auto v:events){
            pq.push({v[1],-v[0]});
            m[v[0]]=v[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        pq.push({newPriority, -eventId});
        m[eventId] = newPriority;
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto[p,e] = pq.top();
            e=-e;
            pq.pop();
        
            if(m.find(e)!=m.end()){
                if(m[e]!=p) continue;
                m.erase(e);
                return e;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */