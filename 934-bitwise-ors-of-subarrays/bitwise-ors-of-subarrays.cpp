class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        set<int> cur;
        cur.insert(0);

        for (int x : arr) {
            set<int> cur2;
            for (int y : cur)
                cur2.insert(x | y);
            cur2.insert(x);
            cur = cur2;
            for (int val : cur)
                ans.insert(val);
        }

        return ans.size();
    }
};
