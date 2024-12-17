class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<int,int>> v;
        vector<int>f(26,0);
        int n = s.size();
        for(int i = 0; i < n; i++){
            f[s[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(f[25-i]>0){
                v.push({25-i,f[25-i]});
            }
        }
        string ans="";
        while(!v.empty()){
            int c = v.top().first;
            int x = v.top().second;
            v.pop();
            int ss=ans.size();
            if(ss>0 && (ans[ss-1]-'a')==c){
                break;
            }
            for(int i = 0;i<min(x,repeatLimit);i++){
                ans += (char)('a'+c);
            }
            int cc,y=0;
            if(!v.empty() && x>repeatLimit){
                cc = v.top().first;
                ans += (char)(cc+'a');
                y = v.top().second;
                v.pop();
                y--;
                if(y!=0)
                    v.push({cc,y});
            }
            x = x - min(x,repeatLimit);
            if(x!=0){
                v.push({c,x});
            }
            cout<<c<<' ';
        }
        return ans;
    }
};