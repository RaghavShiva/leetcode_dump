class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>v(n);
        for(int i = 0; i < n; i++){
            v[i]=nums[i];
        }
        sort(v.begin(),v.end());
        int x = 0;
        unordered_map<int, int> numGroup;
        numGroup.insert(pair<int, int>(v[0], x));

        unordered_map<int, list<int>> groupToList;
        groupToList.insert(
            pair<int, list<int>>(x, list<int>(1, v[0])));

        for (int i = 1; i < nums.size(); i++) {
            if (abs(v[i] - v[i - 1]) > limit) {
                x++;
            }

            numGroup.insert(pair<int, int>(v[i], x));

            if (groupToList.find(x) == groupToList.end()) {
                groupToList[x] = list<int>();
            }
            groupToList[x].push_back(v[i]);
        }
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numGroup[num];
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }
        return nums;
    }
};