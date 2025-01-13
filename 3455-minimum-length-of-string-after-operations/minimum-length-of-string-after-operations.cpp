class Solution {
public:
    int minimumLength(string s) {
        map<char,int>m;
        int c=0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            c++;
            if(m[s[i]]==3){
                m[s[i]]=1;
                c-=2;
            }
        }
        return c;
    }
};