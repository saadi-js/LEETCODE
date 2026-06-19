/*
Problem 236. Lowest Common Ancestor of a Binary Tree

Problem Statement:
Given a binary tree and two nodes p and q,
return their Lowest Common Ancestor (LCA).

LCA is defined as the lowest node in the tree
that has both p and q as descendants
(where a node can be a descendant of itself).

Intuition:
We explore the tree bottom-up.

At every node:
- If it is p or q → return it upward
- If left subtree contains one node and right contains the other
  → current node is LCA

Key Idea:
Postorder DFS traversal:
- Check left subtree
- Check right subtree
- Combine results at current node

Approach:
1. If root is NULL → return NULL
2. If root matches p or q → return root
3. Recursively find:
   - LeftLCA in left subtree
   - RightLCA in right subtree
4. Decision:
   - If both left and right are non-null → root is LCA
   - If only one side is non-null → return that side
   - Else return NULL

Example:
        3
       / \
      5   1
     / \  / \
    6  2 0  8

LCA(5,1) = 3

Why This Works:
We propagate found nodes upward.
First node where both sides return non-null is the LCA.

Time Complexity: O(n)
Space Complexity: O(h)

Pattern Used:
Postorder DFS (Bottom-up recursion)

Key Learning:
LCA problems in binary trees are solved using:
→ bottom-up recursion + partial result propagation
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case: empty subtree
        if(root == NULL)
        {
            return NULL;
        }

        // If current node is p or q, return it upward
        if(root->val == p->val || root->val == q->val)
        {
            return root;
        }

        // Search in left subtree
        TreeNode* LeftLCA = lowestCommonAncestor(root->left, p, q);

        // Search in right subtree
        TreeNode* RightLCA = lowestCommonAncestor(root->right, p, q);

        // If both sides return non-null → current node is LCA
        if(LeftLCA && RightLCA)
        {
            return root;
        }

        // If only left side has result → propagate it
        else if(LeftLCA != NULL)
        {
            return LeftLCA;
        }

        // Otherwise return right side (could be NULL or valid node)
        else
        {
            return RightLCA;
        }
    }
};
