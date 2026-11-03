# Two Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an array of integers `nums` and an integer `target`, return  *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have  ***exactly *one solution**, and you may not use the* same* element twice.

You can return the answer in any order.

 

 **Example 1:** 

 **Input:**  `nums = [2,7,11,15], target = 9`

 **Output:**  `[0,1]`

 **Explanation:** 

The sum of `nums[0]` and `nums[1]` is `2 + 7 = 9`, which equals the target. Therefore, the indices `[0, 1]` are returned.

 **Example 2:** 

 **Input:**  `nums = [3,2,4], target = 6`

 **Output:**  `[1,2]`

 **Explanation:** 

The sum of `nums[1]` and `nums[2]` is `2 + 4 = 6`, which equals the target. Therefore, the indices `[1, 2]` are returned.

 **Example 3:** 

 **Input:**  `nums = [3,3], target = 6`

 **Output:**  `[0,1]`

 **Explanation:** 

The sum of `nums[0]` and `nums[1]` is `3 + 3 = 6`, which equals the target. Therefore, the indices `[0, 1]` are returned.

 

 **Constraints:** 

- 2 <= nums.length <= 104
- -109 <= nums[i] <= 109
- -109 <= target <= 109
- Only one valid answer exists.

 

 **Follow-up:** Can you come up with an algorithm that is less than `O(n2)` time complexity?

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 64.45%)  
**Memory:** 14.8 MB (beats 43.38%)  
**Submitted:** 2026-11-03T23:45:17.623Z  

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>mpp;
    int i,diff,n=nums.size();
    for(i=0;i<n;i++){
        diff=target-nums[i];
        if(mpp.find(diff)!=mpp.end()){
            return{mpp[diff],i};
            }
        mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/two-sum/)