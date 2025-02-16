class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long ans=0ll;
        sort(pizzas.begin(),pizzas.end(),greater<long long>());
        int n = pizzas.size();
        int k = n/4;
        int o = k-k/2;
        int e = k/2;
        int ind=0;
        for(int i=0;i<k;i++){
            if(o>0){
                ans+=pizzas[ind];
                o--;
                ind++;
            }
            else{
                e--;
                ++ind;
                ans+=pizzas[ind];
                ind++;
            }
        }
        return ans;
    }
};