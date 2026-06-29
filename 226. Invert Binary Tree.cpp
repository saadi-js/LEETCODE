/*
Problem 226. Invert Binary Tree

Problem Statement:

Given the root of a binary tree, invert the tree and return its root.

Inverting a binary tree means swapping the left and right child of every
node in the tree.

--------------------------------------------------

Intuition:

Every node in the tree needs to exchange its left and right children.

Since a tree is naturally recursive, we can solve this by processing one
node at a time:

1. Swap the left and right child of the current node.
2. Recursively invert the left subtree.
3. Recursively invert the right subtree.

By repeating this for every node, the entire tree becomes inverted.

--------------------------------------------------

Key Idea:

Step 1: If the current node is NULL, there is nothing to invert.
Step 2: Swap the left and right children.
Step 3: Recursively invert the new left subtree.
Step 4: Recursively invert the new right subtree.
Step 5: Return the root.

--------------------------------------------------

Approach:

1. Check if the current node is NULL.
   - If yes, return NULL.
2. Swap the left and right child pointers.
3. Recursively call the function on the left child.
4. Recursively call the function on the right child.
5. Return the root after the entire subtree has been inverted.

--------------------------------------------------

Example:

Original Tree:

        4
      /   \
     2     7
    / \   / \
   1   3 6   9

After swapping every node:

        4
      /   \
     7     2
    / \   / \
   9   6 3   1

Output:

        4
      /   \
     7     2
    / \   / \
   9   6 3   1

--------------------------------------------------

Counter Example:

Input:

NULL

Since the tree is empty, there are no nodes to swap.

Output:

NULL

--------------------------------------------------

Why This Works:

Every node is visited exactly once.

At each node, its children are swapped before recursively processing
them. Since recursion reaches every node in the tree, every parent-child
relationship is mirrored, producing the inverted tree.

--------------------------------------------------

Time Complexity: O(n)

Every node is visited exactly once.

--------------------------------------------------

Space Complexity: O(h)

Where h is the height of the tree due to the recursive call stack.

Worst case (skewed tree): O(n)

Balanced tree: O(log n)

--------------------------------------------------

Pattern Used:
Binary Tree / Depth-First Search (DFS) / Recursion

Key Learning:

1. Many tree modification problems can be solved by processing the current
   node and then recursively solving the subtrees.
2. Swapping child pointers before recursion simplifies the implementation.
3. Always define a clear base case (`NULL`) to terminate recursion.
4. Recursive tree traversal naturally visits every node exactly once.
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL)
            return NULL;

        // Swap left and right children
        swap(root->left, root->right);

        // Invert both subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
