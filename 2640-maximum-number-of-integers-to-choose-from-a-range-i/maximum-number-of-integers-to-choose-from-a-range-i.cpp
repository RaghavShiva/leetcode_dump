class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>bs;
        
        sort(banned.begin(),banned.end());
        int s = banned.size(), j = 0;
        for(int i = 0; i < s; i++){
            bs.insert(banned[i]);
        }
        vector<int> ban;
        for(auto it:bs){
            ban.push_back(it);
        }
        s = ban.size();
        int ans =0 ;
        for(int i = 1; i <= n; i++){
            if(j < s && ban[j]==i){
                j++;
                continue;
            }
            if(maxSum < i){
                break;
            }
            maxSum -= i;
            ans++;
        }
        return ans;
    }
};