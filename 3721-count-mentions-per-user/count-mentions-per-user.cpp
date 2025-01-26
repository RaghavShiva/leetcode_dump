class Solution {
public:
    vector<int> countMentions(int m, vector<vector<string>>& events) {
        int n = events.size();
        vector<int> v(m,0);
        vector<int> ans(m,0);
        vector<pair<int,pair<int,int>>> temp(n);
        for(int i = 0; i < n; i++){
            auto it = events[i];
            int t = stoi(it[1]);
            if(it[0]=="MESSAGE")
            temp[i]={t,{1,i}};
            else
            temp[i]={t,{0,i}};
        }
        sort(temp.begin(),temp.end());
        for(int i = 0; i < n; i++){
            auto it = events[temp[i].second.second];
            int t = stoi(it[1]);
            if(it[0]=="MESSAGE"){  
                if(it[2]=="ALL"){
                    for(int j = 0; j < m; j++){
                        ans[j]++;
                    }
                }
                else if(it[2]=="HERE"){
                    for(int j = 0; j < m; j++){
                        if(v[j]<=t)
                            ans[j]++;
                    }
                }
                else{
                    string s = it[2];
                    string ss="";
                    for(int j = 0; j < s.size(); j++){
                        if(s[j]==' '){
                            ss=ss.substr(2);
                            int ch = stoi(ss);
                            ss="";
                            ans[ch]++;
                        }
                        else{
                            ss+=s[j];
                        }
                    }
                    ss=ss.substr(2);
                            int ch = stoi(ss);
                            ss="";
                            ans[ch]++;
                }
            }
            else{
                string s = it[2];
                int ch = stoi(s);
                v[ch] = t+60;
            }
        }
        for(int i = 0; i < m; i++){
            cout<<v[i]<<' ';
        }
        return ans;
    }
};