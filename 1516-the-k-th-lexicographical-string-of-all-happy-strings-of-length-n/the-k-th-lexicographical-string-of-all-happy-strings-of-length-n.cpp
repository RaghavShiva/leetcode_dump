class Solution {
public:
    void solve(int n, string &ss, string &s, int i,vector<string>&v){
        if(i==n){
            v.push_back(ss);
            return;
        }
        for(int j=0;j<3;j++){
            if(ss[i-1]==s[j]) continue;
            ss+=s[j];
            solve(n,ss,s,i+1,v);
            ss.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> v;
        string s = "abc",ss="";
        
        for(int i = 0; i < 3; i++){
            ss+=s[i];
            solve(n,ss,s,1,v);
            ss.pop_back();
        }
        sort(v.begin(),v.end());
        if(k > v.size()){
            return "";
        }
        return v[k-1];
    }
};