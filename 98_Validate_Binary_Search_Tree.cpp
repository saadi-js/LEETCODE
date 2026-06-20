/*
Problem 98. Validate Binary Search Tree

Problem Statement:
Given the root of a binary tree, determine if it is a valid Binary Search Tree (BST).

A BST follows:
1. The left subtree of a node contains only nodes with values less than the node's value.
2. The right subtree of a node contains only nodes with values greater than the node's value.
3. Both left and right subtrees must also be valid BSTs.

Intuition:
A common mistake is checking only the immediate children.

Example:

      5
     / \
    4   6
       / \
      3   7

Here:
4 < 5 ✓
6 > 5 ✓
3 < 6 ✓

But 3 is in the right subtree of 5, so it should be greater than 5.
Therefore this is NOT a BST.

We need to maintain valid value boundaries while traversing.

Key Idea:
For every node:
- It must be greater than all nodes in its left ancestry.
- It must be smaller than all nodes in its right ancestry.

Pass:
- Minimum allowed node
- Maximum allowed node

during recursion.

Approach:
1. Start with no bounds:
   helper(root, NULL, NULL)

2. For each node:
   - If min exists and node value <= min value → invalid
   - If max exists and node value >= max value → invalid

3. Recurse:
   - Left child:
     max becomes current node
   - Right child:
     min becomes current node

4. If every node satisfies its range, return true.

Example:

        5
       / \
      3   7
     / \ / \
    2  4 6  8

Node 3:
Range = (-∞, 5)

Node 4:
Range = (3, 5)

Node 6:
Range = (5, 7)

All nodes satisfy their valid ranges.

Why This Works:
Every node is checked against all ancestor constraints,
not just its parent.

This guarantees the BST property globally.

Time Complexity: O(n)

Space Complexity: O(h)

Pattern Used:
DFS with Range Constraints

Key Learning:
BST validation is a range-checking problem,
not a parent-child comparison problem.
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Checks whether subtree rooted at 'root'
    // lies within valid range (min, max)
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        // Empty tree is always a valid BST
        if(root == NULL)
            return true;

        // Current node must be greater than lower bound
        if(min != NULL && root->val <= min->val)
        {
            return false;
        }

        // Current node must be smaller than upper bound
        if(max != NULL && root->val >= max->val)
        {
            return false;
        }

        // Check left subtree
        // Upper bound becomes current node
        // Check right subtree
        // Lower bound becomes current node
        return helper(root->left, min, root) &&
               helper(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {

        // Initially no lower or upper bounds
        return helper(root, NULL, NULL);
    }
};
