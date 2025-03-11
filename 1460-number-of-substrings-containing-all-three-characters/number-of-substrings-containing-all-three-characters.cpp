class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<vector<int>> v(3);
        int n = s.size();
        for(int i=0;i<n;i++){
            v[s[i]-'a'].push_back(i);
        }
        if(v[0].size()==0 || v[1].size()==0 || v[2].size()==0){
            return 0;
        }
        int a=0,b=0,c=0;
        int t = max(v[0][a],max(v[1][b],v[2][c]));
        int ans = n-t;
        for(int i=1;i<n;i++){
            if(s[i-1]=='a'){
                a++;
                if(a==v[0].size()){
                    return ans;
                }
            }
            else if(s[i-1]=='b'){
                b++;
                if(b==v[1].size()){
                    return ans;
                }
            }
            else{
                c++;
                if(c==v[2].size()){
                    return ans;
                }
            }
            t = max(v[0][a],max(v[1][b],v[2][c]));
            ans+=n-t;
        }
        return ans;
    }
};