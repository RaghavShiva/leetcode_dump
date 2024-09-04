class Solution {
public:
    int trap(vector<int>& arr) {
        int ans=0;
        int n = arr.size();
        int l=0,r=n-1,rmx=0,lmx=0;
        while(l<r){
            if(arr[l]<=arr[r]){
                if(lmx>arr[l])
                ans+=lmx-arr[l];
                else
                lmx=arr[l];
                l++;
            }
            else{
                if(rmx>arr[r])
                ans+=rmx-arr[r];
                else
                rmx=arr[r];
                r--;
            }
        }
        return ans;
    }
};