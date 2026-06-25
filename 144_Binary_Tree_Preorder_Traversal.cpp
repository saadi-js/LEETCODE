/*
Problem 144. Binary Tree Preorder Traversal

Problem Statement:
Given the root of a binary tree, return the preorder traversal
of its nodes' values.

Preorder traversal visits nodes in the order:
Root → Left → Right

--------------------------------------------------

Intuition:

In preorder traversal, the root is visited BEFORE its children.
This means the root is always the first element in the output.

This property makes preorder traversal useful for:
- Serializing a tree (recreating it from the output)
- Copying a tree structure
- Constructing a tree (used in Problem 105)

--------------------------------------------------

Key Idea:

Recursively apply the Root → Left → Right pattern:

1. Visit current node (add to result)
2. Recurse on left subtree
3. Recurse on right subtree

Base case: if node is NULL → return immediately.

--------------------------------------------------

Approach:

1. Define helper preorder(root, ans):
   - Base case: if root == NULL, return
   - Push root->val into ans (visit root first)
   - Recurse left
   - Recurse right

2. Call helper from main function.
3. Return ans.

--------------------------------------------------

Example:

        1
       / \
      2   3
     / \
    4   5

Preorder traversal:
Visit 1 → Visit 2 → Visit 4 → Visit 5 → Visit 3

Output: [1, 2, 4, 5, 3]

--------------------------------------------------

The Three Traversals Compared:

Preorder  (Root → Left → Right): [1,2,4,5,3]
Inorder   (Left → Root → Right): [4,2,5,1,3]
Postorder (Left → Right → Root): [4,5,2,3,1]

--------------------------------------------------

Connection to Problem 105:

In Construct Binary Tree from Preorder and Inorder Traversal,
the first element of preorder is always the root.
This is a direct consequence of Root → Left → Right order.

--------------------------------------------------

Time Complexity: O(n)

Every node is visited exactly once.

--------------------------------------------------

Space Complexity: O(h)

Recursion stack depth equals tree height.

--------------------------------------------------

Pattern Used:
Tree DFS / Preorder Traversal (Root → Left → Right)

Key Learning:

1. Preorder = Root → Left → Right. Root is always visited first.
2. Preorder output can reconstruct the tree when combined with
   inorder output (Problem 105).
3. The iterative version uses a stack and processes root first,
   then pushes right child before left (so left is popped first).
4. Understanding all three traversal orders is fundamental for
   any tree-based interview problem.
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

    // Helper: performs preorder traversal recursively
    void preorder(TreeNode* root, vector<int>& ans)
    {
        // Base case: empty node
        if(root == NULL) return;

        // Step 1: Visit current node first
        ans.push_back(root->val);

        // Step 2: Traverse left subtree
        preorder(root->left, ans);

        // Step 3: Traverse right subtree
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        preorder(root, ans);

        return ans;
    }
};
