class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> v;
        int t = log(n)/log(3);
        for(int i=0;i<=t;i++){
            v.push_back(pow(3,i));
        }
        for(int i=t;i>=0;i--){
            if(v[i]<=n){
                n-=v[i];
            }
        }
        return n==0;
    }
};