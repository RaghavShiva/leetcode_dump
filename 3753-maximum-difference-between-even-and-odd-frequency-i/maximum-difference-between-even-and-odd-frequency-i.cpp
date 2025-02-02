class Solution {
public:
    int maxDifference(string s) {
        map<char,int>m;
        int n = s.size();
        for(int i = 0; i < n; i++){
            m[s[i]]++;
        }
        int o=0,e=n;
        for(auto it:m){
            if(it.second%2){
                o=max(o,it.second);
            }
            else{
                e = min(e, it.second);
            }
        }
        return o-e;
    }
};