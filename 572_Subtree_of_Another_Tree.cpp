/*
Problem 572. Subtree of Another Tree

Problem Statement:
Given the roots of two binary trees root and subRoot,
return true if subRoot is a subtree of root.

A subtree means:
- A node in root
- Such that the tree rooted at that node
  is identical to subRoot (structure + values)

Intuition:
We need to:
1. Traverse every node in the main tree
2. At each node, check if subtree matches exactly

So this becomes:
→ Tree traversal + Tree comparison problem

Key Idea:
At every node in root:
- If subtree matches → return true
- Else check left subtree
- Else check right subtree

We reuse a helper function (issame) for tree equality.

Approach:
1. If root is NULL:
   - return true only if subRoot is also NULL
2. If current node matches subRoot root value:
   - check full tree equality using issame()
3. Recursively check:
   - left subtree
   - right subtree

Helper Function (issame):
- Returns true if two trees are identical

Example:
Root:        SubRoot:
   3             4
  / \           / \
 4   5         1   2

Check every node in root for match.

Why This Works:
We try every possible root in the main tree.
At matching value nodes, we validate full structure.

Time Complexity: O(n * m)
Space Complexity: O(h)

Pattern Used:
Tree Traversal + Tree Comparison (DFS)

Key Learning:
Subtree problems = traversal + full tree equality check
*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Helper: check if two trees are identical
    bool issame(TreeNode* p, TreeNode* q)
    {
        // If either node is NULL, both must be NULL
        if(p == NULL || q == NULL)
        {
            return p == q;
        }

        // Check current value + recursively check subtrees
        return p->val == q->val &&
               issame(p->left, q->left) &&
               issame(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // Edge case: if either is NULL
        if(root == NULL || subRoot == NULL)
        {
            return root == subRoot;
        }

        // If current node matches subRoot root value
        if(root->val == subRoot->val && issame(root, subRoot))
        {
            return true;
        }

        // Check left or right subtree
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
