class Solution {
public:
    char kthCharacter(int k) {
       string s="a";
       int n=s.size();
       int l=ceil(log(k)*1.0/log(2));
       for(int i=0;i<l;i++){
        for(int j=0;j<n;j++){
            s+=(char)(s[j]=='z'?'a':s[j]+1);
        }
        n=s.size();
       } 
       return s[k-1];
    }
};