/*
Problem 145. Binary Tree Postorder Traversal

Problem Statement:
Given the root of a binary tree, return the postorder traversal
of its nodes' values.

Postorder traversal visits nodes in the order:
Left → Right → Root

--------------------------------------------------

Intuition:

In postorder traversal, the root is visited AFTER both its children.
Children are fully processed before their parent.

This property makes postorder traversal useful for:
- Deleting a tree (delete children before parent)
- Evaluating expression trees (evaluate operands before operator)
- Computing sizes or heights of subtrees bottom-up

--------------------------------------------------

Key Idea:

Recursively apply the Left → Right → Root pattern:

1. Recurse on left subtree
2. Recurse on right subtree
3. Visit current node (add to result)

Base case: if node is NULL → return immediately.

--------------------------------------------------

Approach:

1. Define helper post(root, ans):
   - Base case: if root == NULL, return
   - Recurse left
   - Recurse right
   - Push root->val into ans (visit root last)

2. Call helper from main function.
3. Return ans.

--------------------------------------------------

Example:

        1
       / \
      2   3
     / \
    4   5

Postorder traversal:
Visit 4 → Visit 5 → Visit 2 → Visit 3 → Visit 1

Output: [4, 5, 2, 3, 1]

--------------------------------------------------

The Three Traversals Compared:

Preorder  (Root → Left → Right): [1,2,4,5,3]
Inorder   (Left → Root → Right): [4,2,5,1,3]
Postorder (Left → Right → Root): [4,5,2,3,1]

--------------------------------------------------

Connection to Other Problems:

Postorder is the natural traversal for:
- Diameter of Binary Tree (543) — compute height bottom-up
- Maximum Depth (104) — return depth from leaves upward
- Lowest Common Ancestor (236) — propagate results upward

All of these use the "process children first, then use their
results at the parent" pattern — which is postorder by definition.

--------------------------------------------------

Time Complexity: O(n)

Every node is visited exactly once.

--------------------------------------------------

Space Complexity: O(h)

Recursion stack depth equals tree height.

--------------------------------------------------

Pattern Used:
Tree DFS / Postorder Traversal (Left → Right → Root)

Key Learning:

1. Postorder = Left → Right → Root. Root is always last.
2. Any problem that computes a value at a node based on its
   children's values is implicitly using postorder logic.
3. The iterative version is trickier — one approach reverses
   a modified preorder (Root → Right → Left) to get postorder.
4. Mastering all three traversals unlocks most tree DFS problems.
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

    // Helper: performs postorder traversal recursively
    void post(TreeNode* root, vector<int>& ans)
    {
        // Base case: empty node
        if(root == NULL) return;

        // Step 1: Traverse left subtree
        post(root->left, ans);

        // Step 2: Traverse right subtree
        post(root->right, ans);

        // Step 3: Visit current node last
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        post(root, ans);

        return ans;
    }
};
