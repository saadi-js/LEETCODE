/*
Problem 21. Merge Two Sorted Lists

Problem Statement:
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted linked list and return its head.

Intuition:
Since both lists are already sorted, we can merge them like the merge step in merge sort.

At each step, we pick the smaller head node and recursively merge the rest.

Key Idea:
At every call:
- Compare current nodes of both lists
- Attach smaller node to result
- Recursively solve for remaining lists

This creates a naturally sorted merged linked list.

Approach:
1. Base cases:
   - If list1 is NULL → return list2
   - If list2 is NULL → return list1

2. Recursive step:
   a. Compare list1->val and list2->val
   b. If list1 is smaller or equal:
        - set list1->next = merge(list1->next, list2)
        - return list1
   c. Else:
        - set list2->next = merge(list1, list2->next)
        - return list2

Example:
list1 = 1 -> 3 -> 5
list2 = 2 -> 4 -> 6

Merged:
1 -> 2 -> 3 -> 4 -> 5 -> 6

Why This Works:
At each step, we greedily pick the smallest element,
and recursion ensures remaining elements stay sorted.

Time Complexity: O(n + m)
Space Complexity: O(n + m) (recursion stack)

Pattern Used:
Recursion + Merge (Merge Sort Technique)

Key Learning:
Whenever two sorted structures are involved:
→ Think merge step of merge sort
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // If first list is empty, return second list
        if(list1 == NULL)
        {
            return list2;
        }

        // If second list is empty, return first list
        if(list2 == NULL)
        {
            return list1;
        }

        // If value in list1 is smaller or equal
        if(list1->val <= list2->val)
        {
            // Recursively merge remaining list1 with list2
            list1->next = mergeTwoLists(list1->next, list2);

            // Return current node of list1
            return list1;
        }
        else
        {
            // Recursively merge list1 with remaining list2
            list2->next = mergeTwoLists(list1, list2->next);

            // Return current node of list2
            return list2;
        }
    }
};
