class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
       vector<int>m(26,0);
        int mod = 1e9+7;
        for(int i = 0; i <s.size(); i++){
            m[s[i]-'a']++;
        }
        while(t--){
            vector<int>mm(26,0);
            
            for(int i = 0; i < 26; i++){
                if(i == 25){
                    mm[0]=(mm[0]+m[25])%mod;
                    mm[1]=(mm[1]+m[25])%mod;
                    m[25]=0;
                }
                else{
                    mm[i + 1]= (mm[i + 1]+m[i])%mod;
                    m[i]=0;
                }
                
            }
            m=mm;
        }
        int ans = 0;
        for(auto it : m){
            ans = (ans+it)%mod;
        }
        return ans;
    }
};