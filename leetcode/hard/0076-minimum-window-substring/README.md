# Minimum Window Substring

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two strings `s` and `t` of lengths `m` and `n` respectively, return  *the  **minimum window***   ***substring**  **of  *`s`*  such that every character in  *`t`*  (** including duplicates**) is included in the window *. If there is no such substring, return* the empty string *`""`.

The testcases will be generated such that the answer is  **unique**.

 

 **Example 1:** 

```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

```

 **Example 2:** 

```
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

```

 **Example 3:** 

```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

```

 

 **Constraints:** 

- m == s.length
- n == t.length
- 1 <= m, n <= 105
- s and t consist of uppercase and lowercase English letters.

 

 **Follow up:**  Could you find an algorithm that runs in `O(m + n)` time?

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 84.72%)  
**Memory:** 11.1 MB (beats 96.75%)  
**Submitted:** 2026-11-04T21:21:27.811Z  

```cpp
#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::vector<int> map(128, 0);
        for (char c : t) {
            map[c]++;
        }
        
        int counter = t.size();
        int begin = 0, end = 0;
        int head = 0;
        int len = INT_MAX;
        
        while (end < s.size()) {
            if (map[s[end]] > 0) {
                counter--;
            }
            map[s[end]]--;
            end++;
            
            while (counter == 0) {
                if (end - begin < len) {
                    len = end - begin;
                    head = begin;
                }
                
                map[s[begin]]++;
                if (map[s[begin]] > 0) {
                    counter++;
                }
                begin++;
            }
        }
        
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/minimum-window-substring/)