/*
Problem 83. Remove Duplicates from Sorted List

Problem Statement:
Given the head of a sorted linked list, delete all duplicates such that each
element appears only once.

Return the linked list sorted as well.

Intuition:
Since the list is already sorted, duplicates will always appear consecutively.
So we only need to compare adjacent nodes.

Key Idea:
If current node value equals next node value:
→ skip the next node by changing pointers

Otherwise:
→ move forward normally

Approach:
1. Start traversal from head
2. Compare current node with next node
3. If equal:
   - delete next node by skipping it
4. Else:
   - move to next node
5. Continue until end of list

Example:

Input:
1 → 1 → 2 → 3 → 3

Step:
1 → 2 → 3

Output:
1 → 2 → 3

Why This Works:
Because the list is sorted, all duplicates are adjacent,
so a single pass is sufficient to remove them.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Linked List In-place Modification / Two-pointer traversal

Key Learning:
Sorted linked list problems often reduce to simple adjacent comparisons.
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

    ListNode* deleteDuplicates(ListNode* head) {

        // Pointer to traverse the list
        ListNode* curr = head;

        // Traverse until last node
        while(curr != NULL && curr->next != NULL)
        {
            // If current value equals next value → duplicate found
            if(curr->val == curr->next->val)
            {
                // Skip the duplicate node
                curr->next = curr->next->next;
            }
            else
            {
                // Move forward if no duplicate
                curr = curr->next;
            }
        }

        // Return modified list
        return head;
    }
};
