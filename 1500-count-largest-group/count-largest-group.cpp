class Solution {
public:
    int sum(int n){
        int s=0;
        while(n!=0){
            s+=n%10;
            n/=10;
        }
        return s;
    }
    int countLargestGroup(int n) {
        vector<int>v(37,0);
        for(int i=1;i<=n;i++){
            int c = sum(i);
            v[c]++;
        }
        int mx = *max_element(v.begin(),v.end());
        int ans = 0;
        for(int i=0;i<37;i++){
            if(mx==v[i]){
                ans++;
            }
        }
        return ans;
    }
};