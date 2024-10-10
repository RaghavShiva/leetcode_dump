class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26,0);
        int maxlen = 0;
        int len = 0;
        int mxf = 0;
        int n = s.size();
        int l = 0, r = 0;
        while(r < n){
            hash[s[r]-'A']++;
            len = r - l + 1;
            mxf = *max_element(hash.begin(),hash.end());
            if(len - mxf > k){
                hash[s[l]-'A']--;
                l++;
                mxf = 0;
                len--;
            }
            r++;
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};