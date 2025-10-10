class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            m[nums[i]]++;

        for (auto& [i, j] : m) {
            if (k == 0) {
                if (j > 1)
                    ans++;
            } else {
                if (m.find(i + k) != m.end())
                    ans++;
            }
        }
        return ans;
    }
};