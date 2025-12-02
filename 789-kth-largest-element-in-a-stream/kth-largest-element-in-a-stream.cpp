class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int kk;
public:
    KthLargest(int k, vector<int>& nums) {
        kk=k;
        for(int x:nums){
            pq.push(x);
            kk--;
            if(kk<0){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        kk--;
        if(kk<0){
            pq.pop();
            kk=0;
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */