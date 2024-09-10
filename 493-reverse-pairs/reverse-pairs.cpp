class Solution {
public:
 void merge(vector<int>& arr, int l, int m, int r)
    {
         vector<int>temp;
         int t=m+1;
         int k=l;
         while(l<=m && t<=r){
             if(arr[l]<=arr[t]){
                 temp.push_back(arr[l]);
                 l++;
             }
             else{
                 temp.push_back(arr[t]);
                 t++;
             }
         }
         while(l<=m){
             temp.push_back(arr[l]);
                 l++;
         }
         while(t<=r){
          temp.push_back(arr[t]);
                 t++;   
         }
         
         for(int x:temp){
             arr[k]=x;
             k++;
         }
    }
    int count(vector<int>& arr,int l,int m,int r){
        int cnt=0;
        int k=m+1;
        while(l<=m && k<=r){
            if(arr[l]>2ll*arr[k]){
                k++;
            }
            else{
                cnt+=0ll+k-m-1;
                l++;
            }
        }
        if(l<=m){
            cnt+=0ll+(m-l+1)*(r-m);
        }
        return cnt;
    }
    int mergeSort(vector<int>& arr, int l, int r)
    {
        //code here
        int cnt=0;
        if(l>=r)
        return cnt;
        int m = l+(r-l)/2;
        cnt+=mergeSort(arr,l,m);
        cnt+=mergeSort(arr,m+1,r);
        cnt+=count(arr,l,m,r);
        merge(arr,l,m,r);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
         return mergeSort(nums,0,nums.size()-1);
    }
};