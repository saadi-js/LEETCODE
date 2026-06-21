/*
Problem 19. Remove Nth Node From End of List

Problem Statement:
Given the head of a linked list, remove the nth node from the end
of the list and return its head.

Intuition:
We need to delete a node based on its position from the end.
Instead of computing length first, we use a two-pointer technique
to achieve one-pass solution.

Key Idea:
Use a dummy node + fast and slow pointers:
- Move fast pointer n steps ahead
- Then move both pointers together
- When fast reaches last node, slow is just before target node

Approach:
1. Create a dummy node pointing to head (handles edge cases)
2. Initialize slow and fast at dummy
3. Move fast n steps ahead
4. Move both until fast reaches last node
5. Delete slow->next node
6. Return dummy->next

Example:

List: 1 → 2 → 3 → 4 → 5, n = 2

Move fast 2 steps:
fast at 2

Move both:
slow and fast move together until fast reaches 5

slow stops at 3
Delete 4

Result: 1 → 2 → 3 → 5

Why This Works:
The gap between fast and slow ensures correct alignment
to identify nth node from the end in one pass.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Two Pointers / Fast-Slow Pointer Technique

Key Learning:
When dealing with "nth from end", always think:
→ fast pointer offset technique
*/




class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Dummy node to handle edge cases (like deleting head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Two pointers starting from dummy
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n steps ahead
        for(int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // Move both pointers until fast reaches last node
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete nth node from end
        slow->next = slow->next->next;

        return dummy->next;
    }
};
