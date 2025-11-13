class Solution {
public:
    int maxOperations(string s) {
        int c=0,n=s.size(),ans=0;
        bool f=false;
        for(int i=n-1;i>=0;i--){
            if(i < n-1 && s[i]=='1' && s[i+1]=='0'){
                c++;
            }
            if(s[i]=='1')
            ans+=c;
        }
       
        return ans;
    }
};