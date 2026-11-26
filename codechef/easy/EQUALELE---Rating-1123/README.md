# EQUALELE - Rating 1123

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Equal Elements

You are given an array $A$ of size $N$. In one operation, you can do the following:

- Select indices $i$ and $j$ $(i\neq j)$ and set $A_i = A_j$.

Find the  **minimum**  number of operations required to make all elements of the array  **equal**.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line of each test case contains an integer $N$ — the size of the array. The next line contains $N$ space-separated integers, denoting the array $A$.
### Output Format

For each test case, output on a new line, the  **minimum**  number of operations required to make all elements of the array  **equal**.

### Constraints
- $1 \leq T \leq 1000$
- $1 \leq N \leq 2\cdot 10^5$
- $1 \leq A_i \leq N$
- The sum of $N$ over all test cases won't exceed $2\cdot 10^5$.
### Sample 1:
Input
Output

```
3
3
1 2 3
4
2 2 3 1
4
3 1 2 4

```

```
2
2
3

```

### Explanation:

 **Test case $1$:**  The minimum number of operations required to make all elements of the array equal is $2$. A possible sequence of operations is:

- Select indices $1$ and $2$ and set $A_1 = A_2 = 2$.
- Select indices $3$ and $2$ and set $A_3 = A_2 = 2$.

Thus, the final array is $[2, 2, 2]$.

 **Test case $2$:**  The minimum number of operations required to make all elements of the array equal is $2$. A possible sequence of operations is:

- Select indices $3$ and $2$ and set $A_3 = A_2 = 2$.
- Select indices $4$ and $3$ and set $A_4 = A_3 = 2$.

Thus, the final array is $[2, 2, 2, 2]$.

 **Test case $3$:**  The minimum number of operations required to make all elements of the array equal is $3$. A possible sequence of operations is:

- Select indices $2$ and $1$ and set $A_2 = A_1 = 3$.
- Select indices $3$ and $1$ and set $A_3 = A_1 = 3$.
- Select indices $4$ and $1$ and set $A_4 = A_1 = 3$.

Thus, the final array is $[3, 3, 3, 3]$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-26T16:51:05.752Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> freq;
        int max_freq = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
            max_freq = max(max_freq, freq[x]);
        }
        cout << n - max_freq << "\n";
    }
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/EQUALELE)