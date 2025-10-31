class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int>m;
        vector<int>ans;
        for(int x:nums){
            m[x]++;
            if(m[x]==2){
                ans.push_back(x);
            }
        }
        return ans;
    }
};