class Solution {
public:
    void solve(int i, int n, int k, set<vector<bool>>&s, vector<bool> v){
        if(k<=0){
            s.insert(v);
            return;
        }
        if(i==4){
            s.insert(v);
            return;
        }
        if(i==3){
            if(k%2){
                for(int j=0;j<n;j++){
                    if(j%3==0)
                    v[j]=!v[j];
                }
            }
            solve(i+1,n,k-1,s,v);
            return;
        }
        solve(i+1,n,k,s,v);
        if(i==0){
            for(int j=0;j<n;j++){
                v[j]=!v[j];
            }
            solve(i+1,n,k-1,s,v);
        }
        else if(i==1){
            for(int j=0;j<n;j++){
                if(j%2){
                    v[j]=!v[j];
                }
            }
            solve(i+1,n,k-1,s,v);
        }
        else{
            for(int j=0;j<n;j++){
                if(j%2==0){
                    v[j]=!v[j];
                }
            }
            solve(i+1,n,k-1,s,v);
        }
        
    }
    int flipLights(int n, int presses) {
        set<vector<bool>>s;
        vector<bool> v(n,true);
        solve(0,n,presses,s,v);
        return (int) s.size();
    }
};