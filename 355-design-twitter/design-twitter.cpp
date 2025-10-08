class Twitter {
    unordered_map<int,vector<pair<int,int>>>twt;
    unordered_map<int,unordered_set<int>>flw;
    int t;
public:

    Twitter() {
        t=0;
    }
    
    void postTweet(int userId, int tweetId) {
        t++;
        twt[userId].push_back({t,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        int k = 10;
        for(auto it:flw[userId]){
            for(auto itt:twt[it]){
                pq.push(itt);
                k--;
                if(k<0){
                    pq.pop();
                    k++;
                }
            }
        }
        for(auto it:twt[userId]){
            pq.push(it);
            k--;
            if(k<0){
                pq.pop();
                k++;
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        flw[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(flw.find(followerId)==flw.end()){
            return;
        }
        auto it = flw[followerId].find(followeeId);
        if(it!=flw[followerId].end())
        flw[followerId].erase(it);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */