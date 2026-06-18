/*
Problem 876. Middle of the Linked List

Problem Statement:

Given the head of a singly linked list, return the middle node.

If there are two middle nodes, return the second middle node.

--------------------------------------------------

Intuition:

A naive approach would be:

1. Traverse the list and count total nodes.
2. Traverse again up to n/2.

This takes two passes.

We can optimize it using the Two Pointer (Fast & Slow) technique.

--------------------------------------------------

Key Idea:

Use two pointers:

- slow → moves one step at a time
- fast → moves two steps at a time

When fast reaches the end, slow will be at the middle.

--------------------------------------------------

Approach:

1. Initialize both pointers at head:
   - slow = head
   - fast = head

2. Traverse while:
   - fast != NULL
   - fast->next != NULL

3. Movement:
   - slow = slow->next
   - fast = fast->next->next

4. When loop ends:
   - slow is at middle node

--------------------------------------------------

Example:

1 → 2 → 3 → 4 → 5

Step-by-step:

slow moves: 1 → 2 → 3
fast moves: 1 → 3 → 5

Fast reaches end → slow = 3 (middle)

--------------------------------------------------

Even Length Case:

1 → 2 → 3 → 4 → 5 → 6

slow ends at 4 (second middle node as required)

--------------------------------------------------

Why This Works:

Fast pointer moves twice as fast as slow pointer.

So when fast reaches the end:
slow has covered exactly half the distance.

--------------------------------------------------

Time Complexity: O(n)

Each node is visited at most once.

--------------------------------------------------

Space Complexity: O(1)

Only two pointers used.

--------------------------------------------------

Pattern Used:
Fast & Slow Pointer (Hare and Tortoise Algorithm)

Key Learning:

1. Fast & slow pointers help detect midpoints efficiently.
2. Also used in cycle detection problems.
3. Very common in linked list interview questions.
4. No need for counting nodes explicitly.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x) {}
 *     ListNode(int x, ListNode *next) : val(x, next) {}
 * };
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // Fast pointer moves 2 steps at a time
        ListNode* fast = head;

        // Slow pointer moves 1 step at a time
        ListNode* slow = head;

        // Traverse while fast pointer can move ahead
        while(fast != NULL && fast->next != NULL)
        {
            // Move slow by one step
            slow = slow->next;

            // Move fast by two steps
            fast = fast->next->next;
        }

        // When fast reaches end, slow is at middle
        return slow;
    }
};
