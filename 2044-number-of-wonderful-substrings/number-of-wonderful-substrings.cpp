class Solution {
public:
    long long wonderfulSubstrings(string word) {
        map<long long,int> f;
        f[0]=1;
        long long m=0;
        int n = word.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int t = word[i]-'a';
            t = 1ll<<t;
            m ^= t;
            ans+=f[m];
            f[m]++;
            
            for(int j=0;j<10;j++){
                if(f[(1ll<<j)^m]){
                    ans+=f[(1ll<<j)^m];
                }
            }
        }
        return ans;
    }
};