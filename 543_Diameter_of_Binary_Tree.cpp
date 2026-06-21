/*
Problem 543. Diameter of Binary Tree

Problem Statement:
Given the root of a binary tree, return the length of the diameter.
The diameter is the longest path between any two nodes in the tree,
and this path may or may not pass through the root.

Intuition:
For every node, the longest path passing through it is:

    left height + right height

So we compute height of each subtree and simultaneously track
the maximum sum of left + right heights.

Key Idea:
Use DFS (postorder traversal) to compute height of each node,
and update global answer with:

    ans = max(ans, leftHeight + rightHeight)

Approach:
1. Define a recursive function height(node)
2. For each node:
   - Compute left subtree height
   - Compute right subtree height
   - Update diameter using left + right
3. Return height = max(left, right) + 1
4. Final answer stored in global variable

Example:

        1
       / \
      2   3
     / \
    4   5

Longest path:
4 → 2 → 1 → 3 or 5 → 2 → 1 → 3
Length = 3 edges

Why This Works:
Every node acts as a potential “bridge” between left and right subtrees.
We evaluate all such bridges via DFS.

Time Complexity: O(n)
Space Complexity: O(h) recursion stack

Pattern Used:
DFS + Tree Height + Global Aggregation

Key Learning:
Diameter problems often reduce to:
→ height(left) + height(right) at each node
*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Stores global maximum diameter
    int ans = 0;

    // DFS function to compute height of tree
    int height(TreeNode* root)
    {
        // Base case: empty node has height 0
        if(root == NULL) return 0;

        // Compute height of left subtree
        int left = height(root->left);

        // Compute height of right subtree
        int right = height(root->right);

        // Update diameter at this node
        ans = max(ans, left + right);

        // Return height of current node
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        // Run DFS to compute diameter
        height(root);

        // Return final computed answer
        return ans;
    }
};
