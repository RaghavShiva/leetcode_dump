class Solution {
public:
    vector<int> factors(int n){
        vector<int> f;
        for(int i=1; i*i<=n;i++){
            if(n%i==0){
                if(i*i!=n){
                    f.push_back(i);
                }
                f.push_back(n/i);
            }
        }
       
        return f;
    }
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
            // int x = groups
            vector<int>f = factors(groups[i]);
            for(int a:f){
                if(m[a]){
                    ans[i]=min(ans[i],m[a]-1);
                }
            }
            if(ans[i]==1e5+1)
            ans[i]=-1;
        }
        return ans;
    }
};