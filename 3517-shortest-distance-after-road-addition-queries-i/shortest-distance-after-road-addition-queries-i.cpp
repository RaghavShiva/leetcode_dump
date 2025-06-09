class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
         vector<vector<int>> adj(n);
   
    for (int i = 0; i < n-1; i++) adj[i].push_back(i+1);
    const int INF = 1e9;
    vector<int> dist(n, INF);
   
    for (int i = 0; i < n; i++) dist[i] = i;

    vector<int> answer;
    deque<int> q;

    
    for (auto& qr : queries) {
        int u = qr[0], v = qr[1];
        adj[u].push_back(v);

        if (dist[u] + 1 < dist[v]) {
            dist[v] = dist[u] + 1;
            q.push_back(v);
        }

        while (!q.empty()) {
            int x = q.front(); q.pop_front();
            for (int y : adj[x]) {
                if (dist[x] + 1 < dist[y]) {
                    dist[y] = dist[x] + 1;
                    q.push_back(y);
                }
            }
        }

        answer.push_back(dist[n-1] < INF ? dist[n-1] : -1);
    }
    return answer;
    }
};