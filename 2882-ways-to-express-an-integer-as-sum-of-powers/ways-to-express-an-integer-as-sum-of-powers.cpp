class Solution {
public:
    int power(int b, int p){
        int mod = 1e9+7;
        int res=1;
        while(p){
            if(p%2){
                res = (res*1ll*b)%mod;
            }
            b=(b*1ll*b)%mod;
            p=p/2;
        }
        return res;
    }
    int solve(vector<vector<int>> &v, int i, int j, int n, int x){
        int mod = 1e9+7;
        if(j==n){
            return 1;
        }
        if(j>n || i>n){
            return 0;
        }
        if(v[i][j]!=-1){
            return v[i][j];
        }
        int temp = power(i,x);
        temp = (j+temp)%mod; 
        int t = solve(v,i+1,temp,n,x);
        int nt = solve(v,i+1,j,n,x);
        v[i][j] = (nt+t)%mod;
        return v[i][j];
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> v(n+1,vector<int>(n+1,-1));
        return solve(v,1,0ll,n,x);
    }
};