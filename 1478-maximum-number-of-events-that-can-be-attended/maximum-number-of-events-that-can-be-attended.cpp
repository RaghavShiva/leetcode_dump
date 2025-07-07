class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxD = 0;
        for (int k = 0; k < n; k++) {
            maxD = max(maxD, events[k][1]);
        }

        priority_queue<int, vector<int>, greater<>> pq;
        sort(events.begin(), events.end());

        int res = 0;
        for (int d = 0, e = 0; d <= maxD; d++) {
            while (e < n && events[e][0] <= d) {
                pq.emplace(events[e][1]);
                e++;
            }
            while (!pq.empty() && pq.top() < d) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                res++;
            }
        }

        return res;
    }
};
