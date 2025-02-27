class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> m;
        int n = arr.size();
        for(int i=0;i<n;i++){
            m.insert(arr[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int f = arr[i];
                int s = arr[j];
                int nxt = f+s;
                int c = 2;
                while(m.find(nxt)!=m.end()){
                    c++;
                    f=nxt;
                    nxt+=s;
                    s=f;
                    ans = max(ans,c);
                }
                
            }
        }
        return ans;
    }
};