class Solution {
public:
    int calc_beauty(vector<int>& freq){
        int bty = 0;
        int mx = 0;
        int mn = 500;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                mn = min(mn, freq[i]);
                mx = max(mx, freq[i]);
            }
        }
        bty = mx - mn;
        return bty;
    }
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            vector<int> freq(26,0);
            for(int j = i; j < n; j++){
                freq[s[j] - 'a']++;
                sum += calc_beauty(freq);
            }
        }
        return sum;
    }
};