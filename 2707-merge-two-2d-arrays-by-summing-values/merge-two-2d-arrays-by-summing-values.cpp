class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int l=0,r=0;
        vector<vector<int>> ans;
        while(l<n1 && r<n2){
            if(nums1[l][0]==nums2[r][0]){
                ans.push_back({nums1[l][0],nums1[l][1]+nums2[r][1]});
                l++;
                r++;
            }
            else if(nums1[l][0]<nums2[r][0]){
                ans.push_back({nums1[l][0],nums1[l][1]});
                l++;
            }
            else{
                ans.push_back({nums2[r][0],nums2[r][1]});
                r++;
            }
        }
        while(l<n1){
            ans.push_back({nums1[l][0],nums1[l][1]});
                l++;
        }
        while(r<n2){
            ans.push_back({nums2[r][0],nums2[r][1]});
                r++;
        }
        return ans;
    }
};