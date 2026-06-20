/*
Problem 1448. Count Good Nodes in Binary Tree

Problem Statement:
Given a binary tree root, a node X in the tree is considered "good"
if on the path from the root to X there are no nodes with a value
greater than X.

Return the number of good nodes in the binary tree.

Intuition:
For every node, we need to know the maximum value encountered
from the root to that node.

If the current node's value is greater than or equal to that maximum,
it is a good node.

Therefore, while traversing the tree, we can carry the maximum value
seen so far along the current root-to-node path.

Key Idea:
Use DFS traversal while maintaining:

maxsofar = maximum value encountered on the path from root to current node.

For each node:
- If node->val >= maxsofar → it is a good node.
- Update maxsofar if needed.
- Recursively process left and right children.

Approach:
1. Start DFS from root with maxsofar = root->val.
2. At each node:
   a. Check if node value is >= maxsofar.
   b. If yes, count it as a good node.
   c. Update maxsofar.
3. Recursively count good nodes in left subtree.
4. Recursively count good nodes in right subtree.
5. Return total count.

Example:

         3
        / \
       1   4
      /   / \
     3   1   5

Path Analysis:

3 → Good
3→1 → Not Good
3→1→3 → Good
3→4 → Good
3→4→1 → Not Good
3→4→5 → Good

Answer = 4

Why This Works:
Each node only depends on information from its root-to-node path.
Passing maxsofar during DFS efficiently maintains that information.

Time Complexity: O(n)

Space Complexity: O(h)

Pattern Used:
DFS with Path State Propagation

Key Learning:
Many tree problems require carrying information from ancestors
to descendants during DFS traversal.
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

    // DFS returns number of good nodes in subtree
    int dfs(TreeNode* root, int maxsofar)
    {
        // Base case: empty node contributes 0
        if(root == nullptr)
            return 0;

        // Count of good nodes from current subtree
        int count = 0;

        // Current node is good if no ancestor is greater
        if(root->val >= maxsofar)
        {
            count = 1;

            // Update maximum value seen on current path
            maxsofar = root->val;
        }

        // Count good nodes in left subtree
        count += dfs(root->left, maxsofar);

        // Count good nodes in right subtree
        count += dfs(root->right, maxsofar);

        return count;
    }

    int goodNodes(TreeNode* root) {

        // Root is always good initially
        return dfs(root, root->val);
    }
};
