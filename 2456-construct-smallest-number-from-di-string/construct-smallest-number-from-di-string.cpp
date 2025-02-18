class Solution {
public:
    bool solve(string pattern, int i, string &s, vector<int>&v){
        if(i==pattern.size()){
            return true;
        }
        if(pattern[i]=='I'){
        for(int j = s[i]-'0';j<10;j++){
            if(v[j-1]==1) continue;
            s+=to_string(j);
            v[j-1]=1;
            if(solve(pattern, i+1,s,v)){
                return true;
            }
            v[j-1]=0;
            s.pop_back();
        }
        }
        else{
        for(int j = s[i]-'0';j>0;j--){
            if(v[j-1]==1) continue;
            s+=to_string(j);
            v[j-1]=1;
            if(solve(pattern, i+1,s,v)){
                return true;
            }
            v[j-1]=0;
            s.pop_back();
        }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string s="";
        vector<int>v(9,0);
        for(int i = 1; i < 10; i++){
            if(v[i-1]==1) continue;
            s+=to_string(i);
            v[i-1]=1;
            if(solve(pattern, 0,s,v)){
                return s;
            }
            v[i-1]=0;
            s.pop_back();
        }
        return s;
    }
};