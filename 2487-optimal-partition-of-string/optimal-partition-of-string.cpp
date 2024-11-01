class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        map<char, int> m;
        int n = s.size();
        for(int i = 0; i < n; i++){
            
            while(i<n){
                if(m[s[i]]){
                    m.clear();
                    m[s[i]]++;
                    ans++;
                    break;
                }
                m[s[i]]++;
                i++;
            }
        }
        return ans+1;
    }
};