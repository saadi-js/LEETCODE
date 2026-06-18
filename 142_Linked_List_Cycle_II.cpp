/*
Problem 142. Linked List Cycle II

Problem Statement:

Given the head of a linked list, return the node where the cycle begins.
If there is no cycle, return NULL.

--------------------------------------------------

Intuition:

A naive approach would be:
- Store visited nodes in a hash set
- First repeated node is cycle start

But this uses O(n) extra space.

We can solve it in O(1) space using Floyd’s Cycle Detection Algorithm.

--------------------------------------------------

Key Idea (Floyd’s Algorithm):

We use two pointers:

- slow → moves 1 step at a time
- fast → moves 2 steps at a time

If a cycle exists, they will eventually meet inside the cycle.

--------------------------------------------------

Important Insight (Cycle Start Logic):

After slow and fast meet:

1. Reset slow to head
2. Move both slow and fast one step at a time
3. The point where they meet again is the cycle start

--------------------------------------------------

Why This Works (Mathematical Insight):

Let:
- distance from head to cycle start = a
- distance from cycle start to meeting point = b
- cycle length = c

When slow and fast meet:
- fast has traveled more distance inside cycle
- relationship guarantees that resetting slow to head
  aligns both pointers to meet at cycle start

--------------------------------------------------

Approach:

1. Initialize:
   - slow = head
   - fast = head

2. Detect cycle:
   - Move slow by 1 step
   - Move fast by 2 steps
   - If slow == fast → cycle detected

3. Find cycle start:
   - Reset slow = head
   - Move both slow and fast one step at a time
   - First meeting point is cycle start

4. If no cycle:
   - return NULL

--------------------------------------------------

Example:

1 → 2 → 3 → 4 → 5
         ↑         ↓
         ← ← ← ← ←

Cycle starts at node 3

--------------------------------------------------

Why This Works:

First phase detects intersection inside cycle.
Second phase uses distance alignment to locate entry point.

--------------------------------------------------

Time Complexity: O(n)

Each pointer traverses at most twice the list.

--------------------------------------------------

Space Complexity: O(1)

Only two pointers used.

--------------------------------------------------

Pattern Used:
Floyd’s Cycle Detection (Fast & Slow Pointer)

Key Learning:

1. Cycle detection is a two-phase process:
   - detect cycle
   - find entry point
2. Fast & slow pointer is powerful for linked list cycles.
3. No extra memory required.
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
    ListNode *detectCycle(ListNode *head) {

        // Slow pointer moves one step
        ListNode* slow = head;

        // Fast pointer moves two steps
        ListNode* fast = head;

        // Phase 1: Detect if cycle exists
        while(fast != NULL && fast->next != NULL)
        {
            // Move slow by 1 step
            slow = slow->next;

            // Move fast by 2 steps
            fast = fast->next->next;

            // If they meet, cycle is detected
            if(slow == fast)
            {
                // Phase 2: Find cycle starting node
                slow = head;

                // Move both pointers one step at a time
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }

                // Meeting point is cycle start
                return slow;
            }
        }

        // No cycle found
        return NULL;
    }
};
