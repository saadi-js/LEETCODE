/*
Problem 2. Add Two Numbers

Problem Statement:
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each node contains a single digit.

Add the two numbers and return the sum as a linked list.

Intuition:
Since digits are stored in reverse order, we can simulate addition
like manual addition (grade-school method), digit by digit.

Key Idea:
Traverse both lists simultaneously and maintain a carry.

At each step:
- sum = l1 + l2 + carry
- new digit = sum % 10
- new carry = sum / 10

Continue until both lists and carry are exhausted.

Approach:
1. Create dummy node to build result list
2. Initialize pointer curr and carry = 0
3. While l1, l2, or carry exists:
   - compute sum
   - extract digit and update carry
   - append new node
4. Return dummy->next

Example:

l1 = 2 → 4 → 3
l2 = 5 → 6 → 4

Step 1: 2 + 5 = 7
Step 2: 4 + 6 = 10 → write 0 carry 1
Step 3: 3 + 4 + 1 = 8

Result: 7 → 0 → 8

Why This Works:
We mimic elementary addition with carry propagation.

Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))

Pattern Used:
Linked List Simulation / Carry Propagation

Key Learning:
When numbers are stored digit-wise in lists, treat it like manual addition.
*/



class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node to build result list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        // Continue while digits or carry exist
        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            int sum = carry;

            // Add l1 digit if available
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add l2 digit if available
            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            // Update carry
            carry = sum / 10;

            // Create new digit node
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next;
    }
};
