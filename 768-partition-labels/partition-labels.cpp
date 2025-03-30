class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26,-1);
        int n = s.size();
        vector<int> ans;
        int c  = -1;
        for(int i=0;i<n;i++){
            v[s[i]-'a']=i;
        }
        int d  = 0;
        for(int i=0;i<n;i++){
            c = max(c,v[s[i]-'a']);
            if(i==c){
                ans.push_back(d+1);
                d=0;
            }
            else{
                d++;
            }
            
        }
        return ans;
    }
};