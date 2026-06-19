/*
Problem 138. Copy List with Random Pointer

Problem Statement:
A linked list is given where each node has:
- next pointer
- random pointer (can point to any node or null)

Return a deep copy of the list.

Intuition:
A normal copy fails because of random pointers pointing anywhere in the list.

We need to preserve mapping between original nodes and their copies.

Key Idea:
Use a hashmap to store:
original node → copied node

Then:
1. First pass: create all nodes (next pointers)
2. Second pass: assign random pointers using map

Approach:
1. If head is NULL → return NULL
2. Create hashmap<Node*, Node*>
3. First traversal:
   - Create copy of each node
   - Link via next pointer
   - Store mapping original → copy
4. Second traversal:
   - Assign random pointers using map
5. Return new head

Example:
Original:
A → B → C
A.random = C, B.random = A, C.random = B

Copied:
A' → B' → C'
Same random structure preserved via mapping.

Why This Works:
Hashmap ensures O(1) lookup for corresponding cloned nodes.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern Used:
HashMap + Linked List Cloning

Key Learning:
When structure has arbitrary pointers (random/graph-like):
→ Use hash map for node mapping
*/





/*
Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // Edge case: empty list
        if(head == NULL)
        {
            return NULL;
        }

        // Map: original node → copied node
        unordered_map<Node*, Node*> m;

        // Create first node of copied list
        Node* newhead = new Node(head->val);

        // Pointer for original list traversal
        Node* oldtemp = head->next;

        // Pointer for new list construction
        Node* newtemp = newhead;

        // Store mapping for head
        m[head] = newhead;

        // Step 1: create next pointers and mapping
        while(oldtemp != NULL)
        {
            Node* copy = new Node(oldtemp->val);

            // Store mapping
            m[oldtemp] = copy;

            // Link copied list
            newtemp->next = copy;

            // Move forward
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        // Reset pointers for random assignment
        oldtemp = head;
        newtemp = newhead;

        // Step 2: assign random pointers
        while(oldtemp != NULL)
        {
            newtemp->random = m[oldtemp->random];

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        // Return deep copied list
        return newhead;
    }
};
