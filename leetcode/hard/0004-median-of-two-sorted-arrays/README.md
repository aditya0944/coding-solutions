# Median of Two Sorted Arrays

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return  **the median**  of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

 

 **Example 1:** 

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

```

 **Example 2:** 

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

```

 

 **Constraints:** 

- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -106 <= nums1[i], nums2[i] <= 106

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 95 MB (beats 86.87%)  
**Submitted:** 2026-11-04T21:21:18.018Z  

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        
        int p1 = 0, p2 = 0;
        int current = 0, previous = 0;
        
        for (int i = 0; i <= total / 2; ++i) {
            previous = current;
            
            if (p1 < m && (p2 >= n || nums1[p1] <= nums2[p2])) {
                current = nums1[p1++];
            } else {
                current = nums2[p2++];
            }
        }
        
        if (total % 2 == 0) {
            return (previous + current) / 2.0;
        } else {
            return current;
        }
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/median-of-two-sorted-arrays/)