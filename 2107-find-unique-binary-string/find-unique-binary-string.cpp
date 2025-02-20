class Solution {
public:
    bool solve(map<string,int>&m, int i,int n,string &s){
        if(i==n){
            if(m.find(s)==m.end())
            return true;
            return false;
        }
        s+="0";
        if(solve(m,i+1,n,s)){
            return true;
        }
        s.pop_back();
        s+="1";
         if(solve(m,i+1,n,s)){
            return true;
        }
        s.pop_back();
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int>m;
        int n = nums.size();
        for(auto s:nums){
            m[s]++;
        }
        string s="";
        solve(m,0,n,s);
        return s;

    }
};