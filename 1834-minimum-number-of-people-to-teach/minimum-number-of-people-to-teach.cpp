class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& langs,
                         vector<vector<int>>& friends) {
        unordered_set<int> needTeach;
        
        for (auto& f : friends) {
            bool canTalk = false;
            unordered_set<int> know(langs[f[0]-1].begin(), langs[f[0]-1].end());
            for (int l : langs[f[1]-1]) {
                if (know.count(l)) {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk) {
                needTeach.insert(f[0]-1);
                needTeach.insert(f[1]-1);
            }
        }
        
        vector<int> freq(n+1, 0);
        int best = 0;
        for (int u : needTeach) {
            for (int l : langs[u]) {
                best = max(best, ++freq[l]);
            }
        }
        
        return needTeach.size() - best;
    }
};
