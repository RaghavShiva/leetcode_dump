class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;

        unordered_map<int,int> m;
        set<int>s;
        for(int i=0;i<n;i++){
            m[hand[i]]++;
            s.insert(hand[i]);
        }
        while(!s.empty()){
            int t = *s.begin();
            int f = groupSize;
            while(f--){
                if(m[t])
                m[t]--;
                else{
                    return false;
                }
                if(m[t]==0){
                    m.erase(t);
                    s.erase(t);
                }
                t++;
            }
        }
        return true;
    }
};