/*
Problem 160. Intersection of Two Linked Lists

Problem Statement:

Given the heads of two singly linked lists, return the node at which
the two lists intersect.

If the two linked lists have no intersection, return NULL.

The intersection is based on node references, not node values.

--------------------------------------------------

Intuition:

If one linked list is longer than the other, their starting points
are not equally distant from the end.

Instead of comparing from the heads immediately, we first align both
lists so that they have the same number of nodes remaining.

Once aligned, we move both pointers together.
The first node where both pointers become equal is the intersection.

--------------------------------------------------

Key Idea:

Step 1: Compute the length of both linked lists.
Step 2: Identify the longer list.
Step 3: Move the pointer of the longer list ahead by the difference
        in lengths.
Step 4: Traverse both lists simultaneously.
Step 5: The first common node (same memory address) is the answer.

--------------------------------------------------

Approach:

1. Create a helper function to calculate the length of a linked list.
2. Find the lengths of both linked lists.
3. Determine which list is longer.
4. Move the pointer of the longer list forward by the length difference.
5. Traverse both lists together:
   - If both pointers point to the same node, return it.
   - Otherwise, move both pointers one step forward.
6. If no common node is found, return NULL.

--------------------------------------------------

Example:

List A:

4 → 1
      \
       8 → 4 → 5

List B:

5 → 6 → 1
          \
           8 → 4 → 5

Lengths:

A = 5
B = 6

Difference = 1

Move pointer of List B ahead by one node.

Now both pointers have the same number of nodes remaining.

Traverse together:

4 ≠ 6

1 ≠ 1

8 == 8 (same node)

Output:
Node with value 8

--------------------------------------------------

Counter Example:

List A:

1 → 2 → 3

List B:

4 → 5

Lengths:

A = 3
B = 2

Move pointer of List A ahead by one node.

Compare:

2 ≠ 4

3 ≠ 5

Both pointers reach NULL.

Output:
NULL

--------------------------------------------------

Why This Works:

After advancing the longer list by the difference in lengths,
both pointers are equally far from the end.

Therefore, if an intersection exists, both pointers will arrive
at the intersection node at the same time.

Comparing node addresses (not values) correctly identifies the
shared node.

--------------------------------------------------

Time Complexity: O(n + m)

Where:
- n = length of List A
- m = length of List B

One traversal computes each length, and one traversal compares
both lists.

--------------------------------------------------

Space Complexity: O(1)

Only a few pointer variables are used.

--------------------------------------------------

Pattern Used:
Linked List / Two Pointers / Length Alignment

Key Learning:

1. Before comparing two linked lists, align them by their remaining lengths.
2. Always compare node addresses (`ptr1 == ptr2`), not node values.
3. Helper functions can simplify linked list problems by separating concerns.
4. Aligning pointers is a common technique for solving linked list intersection problems efficiently.
*/

class Solution {
public:

    int length(ListNode* head)
    {
        int l = 0;
        ListNode* curr = head;

        while(curr != NULL)
        {
            l++;
            curr = curr->next;
        }

        return l;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int l1 = length(headA);
        int l2 = length(headB);

        ListNode* ptr1;
        ListNode* ptr2;

        int d;

        if(l1 > l2)
        {
            ptr1 = headA;
            ptr2 = headB;
            d = l1 - l2;
        }
        else
        {
            ptr1 = headB;
            ptr2 = headA;
            d = l2 - l1;
        }

        // Align both lists
        while(d--)
            ptr1 = ptr1->next;

        // Find the intersection node
        while(ptr1 != NULL && ptr2 != NULL)
        {
            if(ptr1 == ptr2)
                return ptr1;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return NULL;
    }
};
