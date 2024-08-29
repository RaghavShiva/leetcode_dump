class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n1=1e5,n2=1e5,c1=0,c2=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
        if(nums[i]==n1){
            c1++;
        }
        else if(n2==nums[i])
        c2++;
        else if(c1==0){
            c1++;
            n1=nums[i];
        }
        else if(c2==0){
            c2++;
            n2=nums[i];
        }
        else{
            c1--;
            c2--;
        }
       }
       c1=0;
       c2=0;
       for(int i=0;i<n;i++){
        if(nums[i]==n1)
        c1++;
        if(n2==nums[i])
        c2++;
       }
       vector<int> ans;
       if(c1>n/3)
       ans.push_back(n1);
       if(c2>n/3)
       ans.push_back(n2);
       return ans;
    }
};