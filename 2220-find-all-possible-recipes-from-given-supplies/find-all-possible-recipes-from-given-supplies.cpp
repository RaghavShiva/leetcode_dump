class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        int n = recipes.size();
        unordered_map<string,int>mp;
        for(int i=0;i<supplies.size();i++){
            mp[supplies[i]]++;
        }
        vector<bool>v(n,false);
        for(int a=0;a<n;a++){
        for(int i =0;i<n;i++){
            if(v[i])
            continue;
            int m = ingredients[i].size();
            bool take = true;
            for(int j=0;j<m;j++){
                bool f = true;
                if(!mp[ingredients[i][j]]){
                    take = false;
                    break;
                }
            }
            if(take && !v[i]){
                v[i]=true;
                ans.push_back(recipes[i]);
                mp[recipes[i]]++;
            }
        }
        }
        return ans;
    }
};