/*
Problem 206. Reverse Linked List

Problem Statement:

Given the head of a singly linked list, reverse the list and return
the new head.

--------------------------------------------------

Intuition:

A linked list is normally:

head → 1 → 2 → 3 → 4 → NULL

We need to reverse the direction of all pointers:

head ← 1 ← 2 ← 3 ← 4

The core challenge is to reverse links without losing access to nodes.

--------------------------------------------------

Key Idea:

We iteratively change the direction of pointers using three pointers:

1. prev → stores previous node (initially NULL)
2. curr → current node we are processing
3. next → temporarily stores next node

--------------------------------------------------

Approach:

1. Initialize:
   - prev = NULL
   - curr = head

2. While curr is not NULL:
   - Store next node (curr->next)
   - Reverse current node's pointer (curr->next = prev)
   - Move prev forward to curr
   - Move curr forward to next

3. At the end:
   - prev will point to the new head of reversed list

--------------------------------------------------

Example:

Original:
1 → 2 → 3 → 4 → NULL

Step-by-step:

prev = NULL

1: reverse → NULL ← 1
2: reverse → NULL ← 1 ← 2
3: reverse → NULL ← 1 ← 2 ← 3
4: reverse → NULL ← 1 ← 2 ← 3 ← 4

Final head = 4

--------------------------------------------------

Why This Works:

We carefully preserve the next pointer before reversing links.

Without storing next, we would lose the rest of the list.

So at each step:
- Save future node
- Reverse current link
- Move forward safely

--------------------------------------------------

Time Complexity: O(n)

Each node is visited once.

--------------------------------------------------

Space Complexity: O(1)

Only three pointers are used.

--------------------------------------------------

Pattern Used:
Linked List Pointer Manipulation

Key Learning:

1. Always store next node before reversing pointers.
2. Iterative reversal is more efficient than recursion (O(1) space).
3. Three-pointer technique is fundamental for linked list problems.
4. Very common interview question.
*/





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // Pointer to store previous node (initially NULL)
        ListNode* prev = NULL;

        // Pointer to store next node temporarily
        ListNode* next = NULL;

        // Pointer to traverse the list
        ListNode* curr = head;

        // Traverse the entire linked list
        while(curr != NULL)
        {
            // Store next node before breaking the link
            next = curr->next;

            // Reverse the current node's pointer
            curr->next = prev;

            // Move prev forward (current becomes previous)
            prev = curr;

            // Move curr forward using stored next node
            curr = next;
        }

        // prev becomes the new head of reversed list
        return prev;
    }
};
