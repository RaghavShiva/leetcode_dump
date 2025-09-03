class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),[](vector<int> &a, vector<int> &b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        int ans = 0;
        for(int i=0;i<n;i++){
            int xmn = points[i][0]-1;
            int xmx = INT_MAX;
            int ymn = INT_MIN;
            int ymx = points[i][1]+1;
            for(int j=i+1;j<n;j++){
                if(points[j][0]>xmn && points[j][0] <xmx && points[j][1] > ymn && points[j][1]<ymx){
                    ans++;
                    xmn = points[j][0];
                    ymn = points[j][1];
                }
            }
        }
        return ans;
    }
};