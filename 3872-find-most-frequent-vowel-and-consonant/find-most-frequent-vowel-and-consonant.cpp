class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        int d=0,c=0;
        for(int i=0;i<26;i++){
            if(i==0 || i==4 || i==8 || i==14 || i==20){
                d=max(d,v[i]);
            }
            else{
                c = max(c,v[i]);
            }
        }
        return c+d;
            
        
    }
};