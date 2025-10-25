class Solution {
public:
    int totalHammingDistance(vector<int>& arr) {
        int sum=0,n=arr.size();

        vector<int>cnt(32);
        sort(arr.begin(),arr.end());

        for(int i=0;i<n;i++){
            int num=arr[i];

            int pos=0;
            while(num > 0){
                if(i != 0){
                    if(num & 1) sum += (i-cnt[pos]);
                    else sum += cnt[pos];
                }
                if(num & 1) cnt[pos]++;
                num >>= 1;
                pos++;
            }
        }
        return sum;
    }
};