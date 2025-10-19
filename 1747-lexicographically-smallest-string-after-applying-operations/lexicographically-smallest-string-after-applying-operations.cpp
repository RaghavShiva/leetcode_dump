class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        string ans = s;
        queue<string> q;
        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            if (cur < ans) ans = cur;

            string s1 = cur;
            for (int i = 1; i < s1.size(); i += 2)
                s1[i] = ((s1[i] - '0' + a) % 10) + '0';
            if (!vis.count(s1)) {
                vis.insert(s1);
                q.push(s1);
            }

            string s2 = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!vis.count(s2)) {
                vis.insert(s2);
                q.push(s2);
            }
        }
        return ans;
    }
};
