class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l = 0, r = 0;
        int n = arr.size(),i;
        int ans=0;
        for(i = n-1; i > 0; i--){
            if(arr[i]>=arr[i-1]){
                continue;
            }
            break;
        }
        if(i==0){
            return 0;
        }
        ans = i;
        r=i;
        for(l=0;l<n;l++){
            if(l==0 || arr[l-1]<=arr[l]){
            while(r<n && arr[l]>arr[r]){
                r++;
            }
            }
            else{
                r=n;
                ans = min(ans, r - l);
                break;
            }
            ans = min(ans, r - l - 1);
        }
        return ans;
    }
};