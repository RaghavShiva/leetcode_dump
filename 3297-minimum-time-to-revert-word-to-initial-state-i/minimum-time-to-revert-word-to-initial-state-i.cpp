class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int ans = 1;
        int n = word.size();
        for(int i = k; i < n; i+=k){
            bool f = true;
            for(int j = 0; j < n - i; j++){
                if(word[j]!=word[i+j]){
                    f = false;
                }
            }
            if(!f){
                ans++;
            }
            else{
                return ans;
            }
        }
        n = ceil(n*1.0/k);
        return n;
    }
};