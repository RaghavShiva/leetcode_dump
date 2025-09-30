class Solution {
public:
    void dfs(string st, int k, string &ans, unordered_set<string> &s){
        for(int i=0;i<k;i++){
            string str = st+to_string(i);
            if(s.find(str)==s.end()){
                s.insert(str);
                str = str.substr(1);
                dfs(str,k,ans,s);
                ans+=to_string(i);
            }
        }
    }
    string crackSafe(int n, int k) {
        unordered_set<string> s;
        string start(n-1,'0');
        string ans="";
        dfs(start, k, ans, s);
        return ans+start;
    }
};