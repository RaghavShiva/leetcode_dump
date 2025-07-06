class FindSumPairs {
public:
    vector<int> v,vv;
    unordered_map<int,int> m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v = nums1;
        vv = nums2;
        for(int x:vv){
            m[x]++;
        }
    }
    
    void add(int index, int val) {
        m[vv[index]]--;
        vv[index]+=val;
        m[vv[index]]++;
    }
    
    int count(int tot) {
        int n = v.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += m[tot-v[i]];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */