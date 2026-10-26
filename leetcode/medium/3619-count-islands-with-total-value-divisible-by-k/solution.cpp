
using namespace std;

class Solution {
private:
    long long dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        long long sum = grid[i][j];
        grid[i][j] = 0;
        
        int dirs[] = {-1, 0, 1, 0, -1};
        for (int d = 0; d < 4; ++d) {
            int ni = i + dirs[d];
            int nj = j + dirs[d + 1];
            
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > 0) {
                sum += dfs(grid, ni, nj, m, n);
            }
        }
        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long islandSum = dfs(grid, i, j, m, n);
                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
