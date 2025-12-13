class Solution {
public:
    bool isValid(string &s){
        if(s.size()==0){
            return false;
        }
        for(char c:s){
            if((c>='a' && c<='z')||(c>='A' && c<='Z') || (c>='0' && c<='9')|| c=='_'){
                continue;
            }
            return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>e,g,p,r;
        int n = code.size();
        for(int i=0;i<n;i++){
            if(isActive[i] && isValid(code[i])){
                if(businessLine[i]=="electronics"){
                    e.push_back(code[i]);
                }
                else if(businessLine[i]=="grocery"){
                    g.push_back(code[i]);
                }
                else if(businessLine[i]=="pharmacy"){
                    p.push_back(code[i]);
                }
                else if(businessLine[i]=="restaurant"){
                    r.push_back(code[i]);
                }
            }
        }
        vector<string> ans;
        sort(e.begin(),e.end());
        sort(g.begin(),g.end());
        sort(p.begin(),p.end());
        sort(r.begin(),r.end());
        for(int i=0;i<(int)e.size();i++){
            ans.push_back(e[i]);
        }
        for(int i=0;i<(int)g.size();i++){
            ans.push_back(g[i]);
        }
        for(int i=0;i<(int)p.size();i++){
            ans.push_back(p[i]);
        }
        for(int i=0;i<(int)r.size();i++){
            ans.push_back(r[i]);
        }
    
        return ans;
    }
};