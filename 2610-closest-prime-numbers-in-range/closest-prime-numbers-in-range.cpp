class Solution {
public:
    void seive(vector<bool> &v, int n){
        v[0]=true;
        v[1]=true;
        for(int i=2;i<=n;i++){
            if(!v[i]){
                for(int j = 2*i;j<=n;j+=i){
                    v[j]=true;
                }
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> v(right+1,false);
        seive(v,right);
        vector<int> pr;
        for(int i=left;i<=right;i++){
            if(!v[i]){
                pr.push_back(i);
            }
        }
        if(pr.size()<2){
            return {-1,-1};
        }
        int n = pr.size();
        int c=1e6;
        vector<int> ans(2);
        for(int i = 0;i<n-1;i++){
            if(pr[i+1]-pr[i]<c){
                ans[0]=pr[i];
                ans[1]=pr[i+1];
                c=pr[i+1]-pr[i];
            }
        }
        return ans;
    }
};