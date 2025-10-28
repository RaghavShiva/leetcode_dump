class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int d = abs(arr[0]-x);
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(abs(arr[i]-x)<=d && arr[i]<=x){
                l=i;
                d = abs(arr[i]-x);
            }
            else{
                break;
            }
        }
        r=l+1;
        deque<int>dq;
        while(k--){
            int a = l>=0?abs(arr[l]-x):1e9;
            int b = r<n?abs(arr[r]-x):1e9;
            if(a<=b){
                dq.push_front(arr[l]);
                l--;
            }
            else{
                dq.push_back(arr[r]);
                r++;
            }
        }
        vector<int>res;
        while(!dq.empty()){
            res.push_back(dq.front());
            dq.pop_front();
        }
        return res;
    }
};