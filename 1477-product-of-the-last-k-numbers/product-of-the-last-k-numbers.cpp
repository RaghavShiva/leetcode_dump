class ProductOfNumbers {
public:
    vector<int>v;
    ProductOfNumbers() {
        v.push_back(1);
    }
    
    void add(int num) {
        if(num==0){

            v={1};
        }
        else
        v.push_back(num*v.back());
    }
    
    int getProduct(int k) {
        int n = v.size();
        if(n<=k){
            return 0;
        }
        int ans = v[n-1]/v[n-1-k];
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */