class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back({e[1], e[2]});
        }
        
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        dist[0][1] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int d = curr[0];
            int u = curr[1];
            int cur_k = curr[2];
            
            if (u == n - 1) {
                return d;
            }
            
            if (d > dist[u][cur_k]) {
                continue;
            }
            
            for (const auto& edge : g[u]) {
                int v = edge.first;
                int w = edge.second;
                
                int nxt_k = (labels[v] == labels[u]) ? (cur_k + 1) : 1;
                
                if (nxt_k <= k && d + w < dist[v][nxt_k]) {
                    dist[v][nxt_k] = d + w;
                    pq.push({d + w, v, nxt_k});
                }
            }
        }
        
        return -1;
    }
};
