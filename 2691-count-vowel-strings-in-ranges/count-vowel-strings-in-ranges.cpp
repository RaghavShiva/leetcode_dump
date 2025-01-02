class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> v(n+1,0);
        for(int i = 0; i < n; i++){
            int t = words[i].size();
            t--;
            if((words[i][0]=='a' || words[i][0]=='e'||words[i][0]=='i'||words[i][0]=='o'||words[i][0]=='u')
            && (words[i][t]=='a' || words[i][t]=='e'||words[i][t]=='i'||words[i][t]=='o'||words[i][t]=='u')){
                v[i+1]++;
            }
            v[i+1]+=v[i];
        }
        vector<int> ans;
        for(auto it : queries){
            ans.push_back(v[it[1]+1]-v[it[0]]);
        }
        return ans;
    }
};