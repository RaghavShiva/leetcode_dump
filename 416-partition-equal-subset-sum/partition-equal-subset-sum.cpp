class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        	int s=0;
	for(int i=0;i<n;i++){
       s+=arr[i];
	}
	if(n==1 || s%2==1)
	return false;
	int k=s/2;
	 vector<bool>prev(k+1);
     prev[0]=true;
     if(arr[0]<=k)
     prev[arr[0]]=true;
     for(int i=1;i<n;i++){
         vector<bool>cur(k+1);
       for(int j=1;j<=k;j++){
           bool p=false;
           bool np=false;
            if(j>=arr[i])
    p=prev[j-arr[i]];
    np=prev[j];
    cur[j]=(p|np);
       }
       cur[0]=true;
      prev=cur;
     }
    
return prev[k];
    }
};