class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k==1){
            return 0;
        }
        if(n==k){
            return 0;
        }  
        long long ans = 0;
        vector<int> v;
        for(int i=1;i<n;i++){
            v.push_back(weights[i]+weights[i-1]);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k-1;i++){
            ans += v[n-2-i]-v[i];
        }
        return ans;

    }
};