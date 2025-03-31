class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int c = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                c++;
            }
        }
        vector<int>v;
        bool f=false;
        int c0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(c0>0){
                    v.push_back(c0);
                    c0=0;
                }
                
            }
            else{
                c0++;
            }
        }
        if(c0>0)
        v.push_back(c0);
        c0=0;
        n=v.size();
        for(int i=0;i<n-1;i++){
            c0=max(c0,v[i]+v[i+1]);
        }
        
        return c0+c;
    }
};