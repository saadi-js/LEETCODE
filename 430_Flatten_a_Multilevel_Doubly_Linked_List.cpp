/*
Problem 430. Flatten a Multilevel Doubly Linked List

Problem Statement:
You are given a doubly linked list where nodes may have a child pointer
pointing to a separate doubly linked list. Flatten the list so that all
nodes appear in a single-level, depth-first order.

The flattened list should use the next and prev pointers, and all
child pointers should be set to NULL.

--------------------------------------------------

Intuition:

Whenever a node has a child, that child's list needs to be inserted
between the current node and its next node.

This is naturally recursive — the child list itself may also have
nodes with children, so we flatten it recursively first before
connecting it.

--------------------------------------------------

Key Idea:

When we encounter a node with a child:
1. Save the current node's next pointer
2. Recursively flatten the child list
3. Connect current node → flattened child list
4. Walk to the end of the flattened child list
5. Connect end of child list → saved next node
6. Set child pointer to NULL

--------------------------------------------------

Approach:

1. If head is NULL → return NULL.
2. Traverse with curr pointer.
3. When curr->child != NULL:
   a. Save next = curr->next
   b. curr->next = flatten(curr->child) (recursive call)
   c. curr->next->prev = curr
   d. curr->child = NULL
   e. Walk curr to end of inserted child list
   f. If next != NULL: connect curr->next = next, next->prev = curr
4. Move curr = curr->next.
5. Return head.

--------------------------------------------------

Example:

1 - 2 - 3 - 4 - 5 - 6
        |
        7 - 8 - 9 - 10
            |
            11 - 12

Flattened:
1 - 2 - 3 - 7 - 8 - 11 - 12 - 9 - 10 - 4 - 5 - 6

--------------------------------------------------

Why Recursive Flatten of Child?

The child list itself may contain further child pointers.
Recursively flattening it first ensures that by the time we
walk to the "end" of the child list, it is already fully flat
with no more child pointers interrupting our traversal.

--------------------------------------------------

Why Walk to End of Child List?

After inserting the flattened child list, we need to connect
its tail to the saved next node. Since we do not know the
tail in advance, we walk to find it.

--------------------------------------------------

Time Complexity: O(n)

Each node is visited a constant number of times.

--------------------------------------------------

Space Complexity: O(d)

Where d = maximum depth of nesting.
Recursion stack depth equals the nesting level.

--------------------------------------------------

Pattern Used:
Linked List Manipulation + Recursion (DFS Flattening)

Key Learning:

1. When inserting a sublist, always save the next pointer before
   breaking the link — a classic linked list technique.
2. Recursive flattening of children before connecting ensures
   the child tail is always reachable by walking forward.
3. Always update both next and prev pointers (doubly linked).
4. Setting child = NULL after processing is essential to produce
   a valid single-level list.
*/



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        // Base case: empty list
        if(head == NULL) return head;

        Node* curr = head;

        while(curr != NULL)
        {
            if(curr->child != NULL)
            {
                // Save next node before breaking connection
                Node* next = curr->next;

                // Recursively flatten child list and connect
                curr->next = flatten(curr->child);
                curr->next->prev = curr;

                // Remove child pointer
                curr->child = NULL;

                // Walk to the end of the inserted child list
                while(curr->next != NULL)
                {
                    curr = curr->next;
                }

                // Connect end of child list to saved next node
                if(next != NULL)
                {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            // Move to next node
            curr = curr->next;
        }

        return head;
    }
};
