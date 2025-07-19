class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
     sort(folder.begin(),folder.end());
     int n = folder.size();
     vector<string> ans;
     ans.push_back(folder[0]);
     for(int i=1;i<n;i++){
        string s = ans.back();
        s+="/";
        if(folder[i].starts_with(s)){
            continue;
        }
        ans.push_back(folder[i]);
     }
     return ans;
    }
};