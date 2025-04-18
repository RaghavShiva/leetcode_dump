class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s = countAndSay(n-1);
        string ss="";
        int m = s.size();
        char cc=s[m-1];
        int c=0;
        for(int i=m-1;i>=0;i--){
            if(s[i]==cc){
                c++;
            }   
            else{
                ss+=cc;
                ss+=(char)(c+'0');
                
                c=1;
                cc=s[i];
            }
        }
        ss+=cc;
        ss+=(char)(c+'0');
        
        reverse(ss.begin(),ss.end());
        return ss;
    }
};