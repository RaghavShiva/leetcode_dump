class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        set<int>s;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            s.insert(A[i]);
            s.insert(B[i]);
            ans[i]=2*i+2-s.size();
        }
        return ans;
    }
};