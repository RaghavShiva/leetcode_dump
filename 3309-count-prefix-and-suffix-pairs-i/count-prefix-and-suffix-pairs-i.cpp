class Solution {
public:
    bool isPrefixAndSuffix(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();
        if(n>m){
            return false;
        }
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                return false;
            }
            if(s1[n-1-i]!=s2[m-1-i]){
                return false;
            }
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int c = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isPrefixAndSuffix(words[i],words[j])){
                    c++;
                }
            }
        }
        return c;
    }
};