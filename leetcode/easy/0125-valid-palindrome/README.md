# Valid Palindrome

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

A phrase is a  **palindrome**  if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` *if it is a  **palindrome**, or* `false` *otherwise*.

 

 **Example 1:** 

```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

```

 **Example 2:** 

```
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

```

 **Example 3:** 

```
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

```

 

 **Constraints:** 

- 1 <= s.length <= 2 * 105
- s consists only of printable ASCII characters.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 24.84%)  
**Memory:** 10.1 MB (beats 33.48%)  
**Submitted:** 2026-11-04T21:21:54.855Z  

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string str="";
        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9'){
                str+=s[i];
            }
            else if(s[i]>='A'&&s[i]<='Z'){
                str+=(char)(s[i]+32);
            }
        }
        n=str.size();
        for(int i=0;i<n;i++){
            if(str[i]!=str[n-i-1]) return false;
            
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-palindrome/)