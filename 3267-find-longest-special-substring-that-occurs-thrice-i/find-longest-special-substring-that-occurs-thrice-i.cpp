class Solution {
public:
    int maximumLength(string s) {
        vector <string> v;
        int n = s.size();
        for(int i = 0; i < n; i++){
            string t ="";
            for(int j = i; j < n; j++){
                t += s[j];
                if(j>i && s[j]!=s[j-1]){
                    break;
                }
                v.push_back(t);
            }
        }
        sort(v.begin(),v.end());
        n = v.size();
        int ans = -1,t;
        for(int i = 0; i < n-2; i++){
            // cout<<v[i]<<' ';
            if(v[i].compare(v[i+1])==0 && v[i+1].compare(v[i+2])==0){
                t = v[i].size();
                // cout<<v[i]<<' ';
                ans = max(ans, t);
            }
        }
        
        return ans;
    }
};