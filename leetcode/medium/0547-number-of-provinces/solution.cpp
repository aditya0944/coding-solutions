
class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis) {
        vis[node] = 1;

        for (int it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();

        vector<vector<int>> adj(v);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(v, 0);
        int cnt = 0;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }

        return cnt;
    }
};
