class Solution {
public:
    bool hasSameDigits(string s) {
      int n=s.size();
        
        for(int i=0;i<n-2;i++){
            string ss="";
            int k=s.size();
            for(int j=0;j<k-1;j++){
            int t = (s[j]-'0')+(s[j+1]-'0');
            t = t%10;
            ss+=(char)(t+'0');
            }
            s=ss;
            cout<<s<<' ';
        }
        return s[0]==s[1];
    }
};