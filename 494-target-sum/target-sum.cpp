class Solution {
public:
int findWays(vector<int>& a, int k)
{
	// Write your code here.
	int n=a.size();
    
	vector<int>prev(k+1,0);
     prev[0]=1;
      if(a[0]==0)
    prev[0]=2;
     if(a[0]!=0 && a[0]<=k)
     prev[a[0]]=1;
     for(int i=1;i<n;i++){
         vector<int>cur(k+1,0);
       for(int j=0;j<=k;j++){
           int p=0;
           int np=0;
            if(j>=a[i])
    p=prev[j-a[i]];
    np=prev[j];
    cur[j]=(p+np);
       }
      prev=cur;
     }
    return prev[k];
}


int countPartitions(int n, int d, vector<int>& arr){
    int sum = 0;
    for(int i=0; i<n;i++){
        sum += arr[i];
    }
    
    //Checking for edge cases
    if(sum-d <0 || (sum-d)%2 ) return 0;
    
    return findWays(arr,(sum-d)/2);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(n, target,nums);
    }
};