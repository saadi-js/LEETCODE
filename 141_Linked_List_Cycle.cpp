/*
Problem 141. Linked List Cycle

Problem Statement:
Given the head of a linked list, determine if the linked list has a cycle.

A cycle exists if a node can be reached again by continuously following next pointers.

Return true if there is a cycle, otherwise return false.

Intuition:
If we traverse a cycle normally, we will loop infinitely.

So instead of tracking visited nodes using extra space,
we use two pointers moving at different speeds.

Key Idea:
Use Floyd’s Cycle Detection Algorithm (Tortoise and Hare):
- slow pointer moves 1 step at a time
- fast pointer moves 2 steps at a time

If a cycle exists:
→ fast will eventually catch slow inside the cycle

If no cycle exists:
→ fast will reach NULL

Approach:
1. Initialize slow and fast at head
2. Move slow by 1 step, fast by 2 steps
3. If slow == fast → cycle exists
4. If fast reaches NULL → no cycle
5. Return result

Example:
1 → 2 → 3 → 4
        ↑     ↓
        ←-----

slow and fast eventually meet inside loop

Why This Works:
In a cycle, relative speed guarantees eventual collision.
Fast pointer laps slow pointer inside the loop.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Two Pointers (Floyd’s Cycle Detection)

Key Learning:
Whenever cycle detection is required in linked structures:
→ use fast and slow pointers instead of hashing
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {

        // Slow pointer moves 1 step
        ListNode* slow = head;

        // Fast pointer moves 2 steps
        ListNode* fast = head;

        // Traverse list
        while(fast != NULL && fast->next != NULL)
        {
            // Move slow by 1 step
            slow = slow->next;

            // Move fast by 2 steps
            fast = fast->next->next;

            // If they meet → cycle exists
            if(slow == fast)
            {
                return true;
            }
        }

        // If fast reaches NULL → no cycle
        return false;
    }
};
