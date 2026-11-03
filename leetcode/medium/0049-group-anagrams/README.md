# Group Anagrams

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of strings `strs`, group the anagrams together. You can return the answer in  **any order**.

 

 **Example 1:** 

 **Input:**  strs = ["eat","tea","tan","ate","nat","bat"]

 **Output:**  [["bat"],["nat","tan"],["ate","eat","tea"]]

 **Explanation:** 

- There is no string in strs that can be rearranged to form "bat".
- The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
- The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

 **Example 2:** 

 **Input:**  strs = [""]

 **Output:**  [[""]]

 **Example 3:** 

 **Input:**  strs = ["a"]

 **Output:**  [["a"]]

 

 **Constraints:** 

- 1 <= strs.length <= 104
- 0 <= strs[i].length <= 100
- strs[i] consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 20 ms (beats 40.75%)  
**Memory:** 26.2 MB (beats 43.12%)  
**Submitted:** 2026-11-03T23:47:20.275Z  

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
    vector<vector<string>> res;
    for(auto x:strs){
        string t=x;
        sort(t.begin(),t.end());
        mpp[t].push_back(x);
    }
    for(auto x:mpp){
        res.push_back(x.second);
    }
    return res;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/group-anagrams/)