class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string s = "";
        for(int i = 0; i < target.size(); i++){
            char ch = 'a';
            while(target[i]!=ch){
                s+=ch;
                ans.push_back(s);
                ch++;
                s.pop_back();
            }
            s+=ch;
            ans.push_back(s);
        }
        return ans;
    }
};