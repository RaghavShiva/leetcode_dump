class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> v(26,0);
        int n = words2.size();
        for(string s : words2){
            vector<int> freq(26,0);
            for(int j = 0; j < s.size(); j++){
                freq[s[j]-'a']++;
            }
            for(int i = 0; i < 26; i++){
                v[i] = max(v[i],freq[i]);
            }
        }
        vector<string> ans;
        for(string s : words1){
            vector<int> freq(26,0);
            bool f = true;
            for(int j = 0; j < s.size(); j++){
                freq[s[j]-'a']++;
            }
            for(int i = 0; i < 26; i++){
                if(v[i]>freq[i]){
                    f = false;
                    break;
                }
            }
            if(f){
                ans.push_back(s);
            }
        }
        return ans;
    }
};