class Solution {
public:
    bool checkValidCuts(int m, vector<vector<int>>& rectangles) {
       vector<pair<int,int>>h;
        vector<pair<int,int>>v;
        int n = rectangles.size();
        for(int i=0;i<n;i++){
            h.push_back({rectangles[i][1],rectangles[i][3]});
            v.push_back({rectangles[i][0],rectangles[i][2]});
        }
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int t = h[0].second;
        int c=0;
        for(int i = 1;i<n;i++){
            if(h[i].first >= t){
                c++;
                t = max(t, h[i].second);
            }
            else{
                t = max(t, h[i].second);
            }
        }
        if(c>=2){
            return true;
        }
        t = v[0].second;
        c=0;
        for(int i = 1;i<n;i++){
            if(v[i].first >= t){
                c++;
                t = max(t, v[i].second);
            }
            else{
                t = max(t, v[i].second);
            }
        }
        if(c>=2){
            return true;
        }
        return false;
    }
};