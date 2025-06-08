class Solution {
public:
    vector<int>v = {0,1,2,3,4,5,6,7,8,9};
    void dfs(int i, int n,vector<int>&ans){
        if(i>n){
            return;
        }
        ans.push_back(i);
        for(int j:v){
            dfs(i*10+v[j],n,ans);
        }

    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<10;i++){
            dfs(i,n,ans);
        }
        return ans;
    }
};