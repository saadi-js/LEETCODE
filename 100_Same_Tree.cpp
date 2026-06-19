/*
Problem 100. Same Tree

Problem Statement:
Given the roots of two binary trees p and q, determine if they are structurally identical
and have the same node values.

Two trees are the same if:
- They have identical structure
- Corresponding nodes have the same value

Intuition:
We compare both trees simultaneously.
At every step, we ensure:
1. Structure matches
2. Node values match
3. Left and right subtrees also match recursively

Key Idea:
Recursive DFS comparison of both trees at the same position.

Approach:
1. If both nodes are NULL → trees match at this position
2. If one is NULL and other is not → not same tree
3. Recursively compare:
   - left subtree
   - right subtree
4. Ensure current node values are equal

Example:
Tree1:        Tree2:
   1             1
  / \           / \
 2   3         2   3

Both structure + values match → true

Why This Works:
Tree equality is defined structurally and recursively.
So breaking it into subtree comparisons ensures correctness.

Time Complexity: O(n)
Space Complexity: O(h) (recursion stack)

Pattern Used:
Tree DFS (Recursive comparison)

Key Learning:
Tree problems often reduce to:
→ left subtree check + right subtree check + root comparison
*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), left(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // If either node is NULL, both must be NULL to be equal
        if(p == NULL || q == NULL)
        {
            return p == q;
        }

        // Check left subtree recursively
        bool isleftsame = isSameTree(p->left, q->left);

        // Check right subtree recursively
        bool isrightsame = isSameTree(p->right, q->right);

        // Current node values must match AND both subtrees must match
        return isleftsame && isrightsame && p->val == q->val;
    }
};
