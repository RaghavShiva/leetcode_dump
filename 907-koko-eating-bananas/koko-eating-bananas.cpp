class Solution {
public:
    bool fun(vector<int>&piles, int k, int h){
        int n = piles.size();
        int hr=0;
        for(int i=0;i<n;i++){
            h -= (piles[i]-1)/k+1;
        }
        return h>=0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
      sort(piles.begin(),piles.end());
      int n = piles.size();
      int hi = piles[n-1];
      int lo = 1;
      int mid=0;
      while(lo<=hi){
        mid = lo+(hi-lo)/2;
        if(fun(piles,mid,h)){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
      }
        return lo;
    }
};