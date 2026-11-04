# Largest Rectangle in Histogram

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return  *the area of the largest rectangle in the histogram*.

 

 **Example 1:** 

```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

```

 **Example 2:** 

```
Input: heights = [2,4]
Output: 4

```

 

 **Constraints:** 

- 1 <= heights.length <= 105
- 0 <= heights[i] <= 104

## Solution

**Language:** C++  
**Runtime:** 21 ms (beats 60.55%)  
**Memory:** 81.2 MB (beats 84.56%)  
**Submitted:** 2026-11-04T21:24:17.376Z  

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; 
        int max_area = 0;
        heights.push_back(0);
        int n = heights.size();
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                
                max_area = std::max(max_area, h * width);
            }
            st.push(i);
        }
        heights.pop_back();
        
        return max_area;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/largest-rectangle-in-histogram/)