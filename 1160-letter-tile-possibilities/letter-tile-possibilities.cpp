class Solution {
public:
    int solve(vector<int> &f){
        int tc = 0;
        for(int i = 0; i < 26; i++){
            if(f[i]==0){
                continue;
            }
            tc++;
            f[i]--;
            tc+=solve(f);
            f[i]++;
        }
        return tc;
    }
    int numTilePossibilities(string tiles) {
        vector<int> f(26,0);
        int n = tiles.size();
        for(int i = 0; i < n; i++){
            f[tiles[i]-'A']++;
        }
        return solve(f);
    }
};