class SGT{
    private:
    int n;
    vector<int>sg;
    void build(int l, int h, vector<int>&nums, int i){
        if(l==h){
            sg[i]=nums[l];
            return;
        }
        int m = (l+h)/2;
        build(l,m,nums,2*i+1);
        build(m+1,h,nums,2*i+2);
        sg[i] = sg[2*i+1]+sg[2*i+2];   
    }
    int query(int l, int r, int low, int high, int i){
        if(low>r||high<l) return 0;
        if(low>=l && high<=r) return sg[i];
        int mid = (low+high)/2;
        int left = query(l,r,low,mid,2*i+1);
        int right = query(l,r,mid+1,high,2*i+2);
        return left+right;
    }
    void update(int l, int h, int i, int ind, int v){
        if(ind<l||ind>h) return;
        if(l==ind && h==ind){
            sg[i]=v;
            return;
        }
        int m = (l+h)/2;
        if(ind<=m){
            update(l,m,2*i+1,ind,v);
        }
        else{
            update(m+1,h,2*i+2,ind,v);
        }
        sg[i]=sg[2*i+1]+sg[2*i+2];
    }
    public:
    SGT(vector<int> &nums){
        n = nums.size();
        sg.resize(4*n);
        build(0,n-1,nums,0);
    }
    int query(int l, int r){
        return query(l,r,0,n-1,0);
    }
    void update(int ind, int val){
        update(0,n-1,0,ind,val);
    }
};

class NumArray {
public:
    SGT ob;
    NumArray(vector<int>& nums):ob(nums) {
    }
    
    void update(int index, int val) {
        ob.update(index,val);
    }
    
    int sumRange(int left, int right) {
       return ob.query(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */