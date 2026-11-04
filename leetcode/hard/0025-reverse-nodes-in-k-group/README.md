# Reverse Nodes in k-Group

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return  *the modified list*.

`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

 **Example 1:** 

```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

```

 **Example 2:** 

```
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

```

 

 **Constraints:** 

- The number of nodes in the list is n.
- 1 <= k <= n <= 5000
- 0 <= Node.val <= 1000

 

 **Follow-up:**  Can you solve the problem in `O(1)` extra memory space?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 16.3 MB (beats 89.14%)  
**Submitted:** 2026-11-04T21:22:52.132Z  

```cpp
#include <algorithm>

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* curr = &dummy;
        ListNode* nex = &dummy;
        ListNode* pre = &dummy;
        
        int count = 0;
        while (curr->next) {
            curr = curr->next;
            count++;
        }
        
        while (count >= k) {
            curr = pre->next;
            nex = curr->next;
            for (int i = 1; i < k; ++i) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            count -= k;
        }
        
        return dummy.next;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/reverse-nodes-in-k-group/)