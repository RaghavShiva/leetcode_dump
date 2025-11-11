class Solution {
public:
    void dfs(string s, double c, map<string,vector<pair<string,double>>>&mp, map<string,double>&mp1){
        mp1[s]=c;
        for(auto it:mp[s]){
            if(mp1.find(it.first)==mp1.end()){
                dfs(it.first, it.second*c,mp,mp1);
            }
        }
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        int n = pairs1.size();
        int m = pairs2.size();
        map<string,vector<pair<string,double>>>g1;
        for(int i=0;i<n;i++){
            g1[pairs1[i][0]].push_back({pairs1[i][1],rates1[i]});
            g1[pairs1[i][1]].push_back({pairs1[i][0],1.0/rates1[i]});
        }
        map<string,double>mp1;
        dfs(initialCurrency,1.0,g1,mp1);
        map<string,vector<pair<string,double>>>g2;
        for(int i=0;i<m;i++){
            g2[pairs2[i][0]].push_back({pairs2[i][1],1.0/rates2[i]});
            g2[pairs2[i][1]].push_back({pairs2[i][0],rates2[i]});
        }
        map<string,double>mp2;
        dfs(initialCurrency,1.0,g2,mp2);
        double ans=1.0;
        for(auto it:mp1){
            if(mp2[it.first]){
                ans = max(ans, it.second*mp2[it.first]);
            }
        }
        return ans;
    }
};