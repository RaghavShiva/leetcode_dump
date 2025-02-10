class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size();
        unordered_map<int,int>m;
        for(int i=0;i<elements.size();i++){
            int a=elements[i];
            if(!m[a]){
                m[a]=i+1;
            }
        }
        vector<int>ans(n,1e5+1);
        for(int i=0;i<n;i++){
            int x = groups[i];
            for(int j=1; j*j<=x;j++){
            if(x%j==0){
              if(m[j]){
                ans[i]=min(ans[i],m[j]-1);
              }
              if(m[x/j]){
                ans[i]=min(ans[i],m[x/j]-1);
              }
            }
        }
            if(ans[i]==1e5+1)
            ans[i]=-1;
        }
        return ans;
    }
};