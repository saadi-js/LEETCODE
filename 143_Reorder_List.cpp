/*
Problem 143. Reorder List

Problem Statement:
Given the head of a singly linked list L0 → L1 → ... → Ln-1 → Ln,
reorder it to:
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...

You must do this in-place without modifying node values.

Intuition:
We need to interleave nodes from both ends of the list.

Direct access from the end is not possible in a singly linked list,
so we simulate it using:
1. Find middle of list
2. Reverse second half
3. Merge two halves alternately

Key Idea:
Break problem into 3 standard linked list operations:
- Middle finding (slow/fast pointers)
- Reversing a linked list
- Merging two lists alternately

Approach:
1. Find middle of linked list using slow and fast pointers.
2. Split list into two halves:
   - first half: head → middle
   - second half: middle.next → end
3. Reverse second half.
4. Merge both halves alternately:
   - take one node from first half
   - then one from reversed second half
5. Continue until second half is exhausted.

Example:
1 → 2 → 3 → 4 → 5

Split:
1 → 2 → 3
4 → 5

Reverse second:
5 → 4

Merge:
1 → 5 → 2 → 4 → 3

Why This Works:
We convert the problem into three well-known subproblems.
Reversing second half allows O(1) access to “end side” nodes.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Linked List Manipulation (Split + Reverse + Merge)

Key Learning:
Complex linked list problems are often combinations of:
→ find middle + reverse + merge
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

    // Find middle of linked list (slow/fast pointer)
    ListNode* midd(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast by 2 and slow by 1
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Reverse linked list
    ListNode* reverses(ListNode* head)
    {
        ListNode* next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            next = curr->next;   // store next node
            curr->next = prev;   // reverse pointer
            prev = curr;         // move prev forward
            curr = next;         // move curr forward
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        // Edge case: 0 or 1 node
        if(head == NULL || head->next == NULL)
            return;

        // Step 1: Find middle
        ListNode* middle = midd(head);

        // Step 2: Split second half
        ListNode* second = middle->next;
        middle->next = nullptr;

        // Step 3: Reverse second half
        second = reverses(second);

        // Step 4: Merge alternating nodes
        ListNode* first = head;

        while(second != NULL)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
