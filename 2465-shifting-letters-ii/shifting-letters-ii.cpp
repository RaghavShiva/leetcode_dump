class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> v(n+1,0);
        for(auto it:shifts){
            if(it[2]==1){
                v[it[0]]++;
                v[it[1]+1]--;
            }
            else{
                v[it[0]]--;
                v[it[1]+1]++;
            }
        }
        for(int i = 1; i < n; i++){
            v[i]+=v[i-1];
        }
        for(int i = 0; i < n; i++){
            if(v[i]<0){
                int t = abs(v[i]);
                t = t%26;
                
                s[i] = (char)('a'+((s[i]-t+26-97)%26));
            }
            else if(v[i]>0){
                int t = abs(v[i]);
                t = t%26;
                s[i] = (char)('a'+((s[i]+t-97)%26));
            }
        }
        return s;
    }
};