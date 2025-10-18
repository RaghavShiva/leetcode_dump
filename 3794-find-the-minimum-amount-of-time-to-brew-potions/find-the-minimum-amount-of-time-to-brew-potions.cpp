using ll = long long;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<ll> time(n,0);
        time[0] = skill[0]*mana[0];
        for(int i=1;i<n;i++){
            time[i] = skill[i]*mana[0]+time[i-1];
        }
        
        for(int i=1;i<m;i++){
            ll end = 0;
            for(int j=0;j<n;j++){
                end = max(end, time[j])+skill[j]*mana[i];
            }
            time[n-1] = end;
            for(int j=n-2;j>=0;j--){
                time[j] = time[j+1]-skill[j+1]*mana[i];
            }
        }
        return time[n-1];
    }
};