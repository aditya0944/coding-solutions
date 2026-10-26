# Count Islands With Total Value Divisible by K

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` matrix `grid` and a positive integer `k`. An  **island**  is a group of  **positive**  integers (representing land) that are  **4-directionally**  connected (horizontally or vertically).

The  **total value**  of an island is the sum of the values of all cells in the island.

Return the number of islands with a total value  **divisible by**  `k`.

 

 **Example 1:** 

 **Input:**  grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5

 **Output:**  2

 **Explanation:** 

The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.

 **Example 2:** 

 **Input:**  grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3

 **Output:**  6

 **Explanation:** 

The grid contains six islands, each with a total value that is divisible by 3.

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 1000
- 1 <= m * n <= 105
- 0 <= grid[i][j] <= 106
- 1 <= k <= 106

## Solution

**Language:** C++  
**Runtime:** 23 ms (beats 87.74%)  
**Memory:** 80.4 MB (beats 83.01%)  
**Submitted:** 2026-10-26T20:55:50.207Z  

```cpp

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

```

---

[View on LeetCode](https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/)