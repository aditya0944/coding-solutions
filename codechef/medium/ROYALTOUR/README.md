# ROYALTOUR

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Royal Tour

Chef has a king on a chessboard with $N$ rows and $M$ columns. The rows are numbered $1$ to $N$ from top to bottom, and the columns are numbered $1$ to $M$ from left to right. The king starts at cell $(r, c)$.

In one move, the king can go to any cell adjacent to its current cell horizontally, vertically or diagonally (up to $8$ cells), without leaving the board.

Find the minimum number of moves the king needs to visit all four corner cells $(1, 1)$, $(1, M)$, $(N, 1)$ and $(N, M)$.

The corners may be visited in any order, and the king may finish anywhere. A corner counts as visited if the king stands on it at any moment, including the start.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains two space-separated integers $N$ and $M$ — the number of rows and columns of the board. The second line contains two space-separated integers $r$ and $c$ — the starting cell of the king.
### Output Format

For each test case, output on a new line the minimum number of moves the king needs to visit all four corners.

### Constraints
- $1 \leq T \leq 10^4$
- $1 \leq N, M \leq 10^9$
- $1 \leq r \leq N$
- $1 \leq c \leq M$
### Sample 1:
Input
Output

```
4
2 5
1 1
3 3
2 2
1 10
1 4
4 7
2 6

```

```
6
7
12
13

```

### Explanation:

 **Test case $1$:**  The king moves from $(1, 1)$ to $(2, 1)$, then along row $2$ to $(2, 5)$, and finally to $(1, 5)$. This takes $1 + 4 + 1 = 6$ moves.

 **Test case $2$:**  The king first moves to $(1, 1)$, and then visits $(1, 3)$, $(3, 3)$ and $(3, 1)$ in this order, using $2$ moves for each. This takes $1 + 2 + 2 + 2 = 7$ moves.

 **Test case $3$:**  The board has a single row, so the corners are just cells $(1, 1)$ and $(1, 10)$. The king walks $3$ moves left to $(1, 1)$ and then $9$ moves right to $(1, 10)$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-25T15:00:42.485Z  

```c_cpp
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

long long dist(long long r1, long long c1, long long r2, long long c2) {
    return max(abs(r1 - r2), abs(c1 - c2));
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N, M, r, c;
        cin >> N >> M;
        cin >> r >> c;

        vector<pair<long long, long long>> corners = {
            {1, 1},
            {1, M},
            {N, 1},
            {N, M}
        };

        vector<int> p = {0, 1, 2, 3};
        long long ans = LLONG_MAX;

        do {
            long long moves = dist(r, c,
                                  corners[p[0]].first,
                                  corners[p[0]].second);

            for (int i = 1; i < 4; i++) {
                moves += dist(corners[p[i - 1]].first,
                              corners[p[i - 1]].second,
                              corners[p[i]].first,
                              corners[p[i]].second);
            }

            ans = min(ans, moves);

        } while (next_permutation(p.begin(), p.end()));

        cout << ans << '\n';
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/ROYALTOUR)