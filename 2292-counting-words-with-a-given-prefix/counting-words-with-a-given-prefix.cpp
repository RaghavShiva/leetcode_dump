class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(string s:words){
            if(s.compare(0,pref.size(),pref)==0){
                ans++;
            }
        }
        return ans;
    }
};