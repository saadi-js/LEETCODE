/*
Problem 104. Maximum Depth of Binary Tree

Problem Statement:
Given the root of a binary tree, return its maximum depth.
Maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.

Intuition:
The depth of a tree is determined by the deeper of its two subtrees.
So at every node, we compare:
- depth of left subtree
- depth of right subtree

Key Idea:
Use recursion (DFS) to compute depth bottom-up:
- depth(node) = max(depth(left), depth(right)) + 1

Approach:
1. If node is NULL → return 0
2. Recursively compute:
   - left subtree depth
   - right subtree depth
3. Return max(left, right) + 1

Example:

        1
       / \
      2   3
     /
    4

Depth = 3 (path: 1 → 2 → 4)

Why This Works:
Each node contributes 1 level, and the deepest subtree
determines the final depth.

Time Complexity: O(n)
Space Complexity: O(h) recursion stack

Pattern Used:
DFS / Tree Height Computation

Key Learning:
Tree depth problems are naturally solved using postorder recursion.
*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr) {}
 *     TreeNode(int x) : val(0), left(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int maxDepth(TreeNode* root) {

        // Base case: empty tree has depth 0
        if(root == NULL) return 0;

        // Recursively compute left subtree depth
        int leftdept = maxDepth(root->left);

        // Recursively compute right subtree depth
        int rightdepth = maxDepth(root->right);

        // Current node contributes +1 to maximum depth path
        return max(leftdept, rightdepth) + 1;
    }
};
