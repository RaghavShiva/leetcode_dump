class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = n+1;
        for(int i=1;i<=6;i++){
            int c=0;
            bool f = true;
            for(int j=0;j<n;j++){
                if(tops[j]==i){
                    continue;
                }
                if(bottoms[j]==i){
                    c++;
                }
                else{
                    f=false;
                    break;
                }
            }
            if(f){
                ans = min(ans,c);
            }
        }
        for(int i=1;i<=6;i++){
            int c=0;
            bool f = true;
            for(int j=0;j<n;j++){
                if(bottoms[j]==i){
                    continue;
                }
                if(tops[j]==i){
                    c++;
                }
                else{
                    f=false;
                    break;
                }
            }
            if(f){
                ans = min(ans,c);
            }
        }
        return ans<=n?ans:-1;
    }
};