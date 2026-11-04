# Longest Substring Without Repeating Characters

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, find the length of the  **longest**   **substring**  without duplicate characters.

 

 **Example 1:** 

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

```

 **Example 2:** 

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

```

 **Example 3:** 

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

```

 

 **Constraints:** 

- 0 <= s.length <= 105
- s consists of English letters, digits, symbols and spaces.

## Solution

**Language:** C++  
**Runtime:** 8 ms (beats 87.36%)  
**Memory:** 19.1 MB (beats 71.00%)  
**Submitted:** 2026-11-04T21:21:45.952Z  

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j,l=0,m=0,n=s.size();
    vector<int> mpp(256,-1);
    for(j=0;j<n;j++){
        if(mpp[s[j]]>=i){
            i=mpp[s[j]]+1;
        }
        mpp[s[j]]=j;
        l=j-i+1;
        m=max(l,m);
    }
    return m;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)