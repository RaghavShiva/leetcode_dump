class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s=" ";
        for(string c:chunks){
            s+=c;
        }
        s+=" ";
        unordered_map<string,int>m;
        int n = s.size();
        string ss = "";

        for(int i=1;i<n;i++){
            if(s[i]==' '){
                if(!ss.empty())
                m[ss]++;
               
                ss="";
                continue;
            }

            if(s[i]=='-'){
                if(s[i-1]=='-' || s[i-1]==' '){
               
                    continue;
                }
                    
                if(s[i+1]=='-' || s[i+1]==' '){
                    if(!ss.empty())
                    m[ss]++;
                    ss="";
                    continue;
                }
            }
            ss+=s[i];     
        }
       
        vector<int>ans;
        for(string q:queries){
            ans.push_back(m[q]);
        }
        return ans;
        
    }
};