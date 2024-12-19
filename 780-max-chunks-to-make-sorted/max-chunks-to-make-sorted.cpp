class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            sort(arr.begin(),arr.begin()+i+1);
            if(i==arr[i]){
                ans++;
            }
        }
        return ans;
    }
};