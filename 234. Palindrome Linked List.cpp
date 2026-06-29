/*
Problem 234. Palindrome Linked List

Problem Statement:

Given the head of a singly linked list, return true if the linked list
is a palindrome, or false otherwise.

A palindrome reads the same forward and backward.

--------------------------------------------------

Intuition:

To determine whether a linked list is a palindrome, we need to compare
its first half with its second half in reverse order.

Unlike an array, we cannot move backwards in a singly linked list.
Therefore, we:

1. Find the middle of the linked list.
2. Reverse the second half.
3. Compare both halves node by node.

If every corresponding value matches, the linked list is a palindrome.

--------------------------------------------------

Key Idea:

Step 1: Use the slow and fast pointer technique to find the middle.
Step 2: If the list has an odd number of nodes, skip the middle node.
Step 3: Reverse the second half of the linked list.
Step 4: Compare the first half and the reversed second half.
Step 5: If all values match, return true; otherwise, return false.

--------------------------------------------------

Approach:

1. Initialize two pointers:
   - slow moves one step at a time.
   - fast moves two steps at a time.
2. Traverse until fast reaches the end.
3. If fast is not NULL after traversal, the list has an odd length,
   so move slow one extra step to skip the middle node.
4. Reverse the linked list starting from slow.
5. Compare nodes from:
   - The beginning of the list.
   - The beginning of the reversed second half.
6. If any values differ, return false.
7. If all nodes match, return true.

--------------------------------------------------

Example:

Input:

1 -> 2 -> 2 -> 1

Step 1:
Find middle

slow points to second 2

Step 2:
Reverse second half

2 -> 1

becomes

1 -> 2

Step 3:
Compare

1 == 1 ✔
2 == 2 ✔

All nodes match.

Output:
true

--------------------------------------------------

Counter Example:

Input:

1 -> 2

Middle:

slow points to 2

Reverse second half:

2

Compare:

1 != 2

Output:
false

--------------------------------------------------

Why This Works:

The slow-fast pointer technique splits the list into two halves.

Reversing the second half allows us to compare both halves in the
same forward direction.

Skipping the middle node in odd-length lists ensures that the center
element, which does not affect palindrome symmetry, is ignored.

If every pair of corresponding nodes matches, the linked list is a
palindrome.

--------------------------------------------------

Time Complexity: O(n)

- Finding the middle: O(n)
- Reversing the second half: O(n)
- Comparing both halves: O(n)

Overall complexity remains O(n).

--------------------------------------------------

Space Complexity: O(1)

The list is modified in-place using only a few pointer variables.

--------------------------------------------------

Pattern Used:
Linked List / Fast & Slow Pointers / In-Place Reversal

Key Learning:

1. Fast and slow pointers efficiently locate the middle of a linked list.
2. Reversing the second half enables comparison without extra memory.
3. For odd-length lists, skip the middle node before reversing.
4. Combining multiple linked list techniques often leads to optimal O(1) space solutions.
*/

class Solution {
public:

    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        if(head == NULL)
            return NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the linked list
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Skip the middle node for odd-length lists
        if(fast != NULL)
        {
            slow = slow->next;
        }

        // Reverse the second half
        ListNode* second = reverse(slow);
        ListNode* first = head;

        // Compare both halves
        while(second != NULL)
        {
            if(second->val != first->val)
            {
                return false;
            }

            second = second->next;
            first = first->next;
        }

        return true;
    }
};
