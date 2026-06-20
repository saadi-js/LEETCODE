/*
Problem 230. Kth Smallest Element in a BST

Problem Statement:
Given the root of a Binary Search Tree (BST) and an integer k,
return the kth smallest value in the BST.

Intuition:
In a BST, inorder traversal gives nodes in sorted (ascending) order.

So instead of sorting or using extra structures, we can:
→ Perform inorder traversal
→ Count nodes as we visit them
→ Return the kth visited node

Key Idea:
Use inorder traversal (Left → Root → Right)
and maintain a global counter to track visit order.

When counter reaches k → return current node value.

Approach:
1. Perform inorder traversal:
   - Visit left subtree
   - Process root
   - Visit right subtree

2. Maintain a global variable prevorder:
   - Tracks how many nodes have been visited

3. At each node:
   - Increment counter
   - If counter == k → return node value immediately

4. Propagate result back up recursion stack.

Example:

BST:
        5
       / \
      3   6
     / \
    2   4

Inorder traversal:
2 → 3 → 4 → 5 → 6

k = 3 → answer = 4

Why This Works:
BST inorder traversal naturally produces sorted order.
So kth smallest is simply kth element in inorder sequence.

Time Complexity: O(n)
Space Complexity: O(h)

Pattern Used:
Inorder Traversal (BST → Sorted Sequence)

Key Learning:
BST problems often become easier when transformed into inorder traversal problems.
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Global counter to track inorder position
    int prevorder = 0;

    int kthSmallest(TreeNode* root, int k) {

        // Base case: empty subtree
        if(root == NULL)
            return -1;

        // Traverse left subtree first (smaller values)
        if(root->left != NULL)
        {
            int leftans = kthSmallest(root->left, k);

            // If answer found in left subtree, propagate it upward
            if(leftans != -1)
                return leftans;
        }

        // Visit current node
        if(prevorder + 1 == k)
        {
            return root->val;
        }

        // Increment count after visiting node
        prevorder += 1;

        // Traverse right subtree (larger values)
        if(root->right != NULL)
        {
            int rightans = kthSmallest(root->right, k);

            // If answer found in right subtree, return it
            if(rightans != -1)
                return rightans;
        }

        return -1;
    }
};
