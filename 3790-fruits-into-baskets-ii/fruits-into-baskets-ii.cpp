class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
     int n = fruits.size();
     vector<int> v(n,0);
     int ans = 0;
     for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(!v[j] && baskets[j]>=fruits[i]){
                v[j]=1;
                ans++;
                break;
            }
        }
     }   
     return n -ans;
    }
};