#define vll vector<long long int>
#define ll long long int
#define fo(i,a,b) for(ll i=a;i<b;++i)
class Solution {
public:
    int factorial(ll n){
        ll M = 1000000007;
        ll f = 1,i;
        fo(i,1,n+1)
            f = (f *1ll* i) % M; 
        return f;
        }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[i]<=complexity[0]){
                return 0;
            }
        }
        return factorial(n-1);
    }
};