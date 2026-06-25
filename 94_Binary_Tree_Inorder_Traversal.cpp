/*
Problem 94. Binary Tree Inorder Traversal

Problem Statement:
Given the root of a binary tree, return the inorder traversal
of its nodes' values.

Inorder traversal visits nodes in the order:
Left → Root → Right

--------------------------------------------------

Intuition:

Tree traversals are naturally recursive — each subtree follows
the same visiting pattern as the whole tree.

Inorder traversal is particularly important for Binary Search Trees
because it visits nodes in sorted (ascending) order.

--------------------------------------------------

Key Idea:

Recursively apply the Left → Root → Right pattern:

1. Recurse on left subtree
2. Visit current node (add to result)
3. Recurse on right subtree

Base case: if node is NULL → return immediately.

--------------------------------------------------

Approach:

1. Define helper inorder(root, ans):
   - Base case: if root == NULL, return
   - Recurse left
   - Push root->val into ans
   - Recurse right

2. Call helper from main function with empty ans vector.
3. Return ans.

--------------------------------------------------

Example:

        1
         \
          2
         /
        3

Inorder traversal:
Left of 1 → NULL
Visit 1
Left of 2 → visit 3
Visit 2
Right of 2 → NULL

Output: [1, 3, 2]

--------------------------------------------------

BST Property:

For a Binary Search Tree, inorder traversal always produces
a sorted sequence. This is why problems like Kth Smallest
Element in BST use inorder traversal directly.

--------------------------------------------------

The Three Traversals Compared:

Inorder   (Left → Root → Right): sorted output for BST
Preorder  (Root → Left → Right): used to serialize/copy a tree
Postorder (Left → Right → Root): used to delete/evaluate a tree

--------------------------------------------------

Time Complexity: O(n)

Every node is visited exactly once.

--------------------------------------------------

Space Complexity: O(h)

Recursion stack depth equals tree height h.
Worst case O(n) for skewed tree, O(log n) for balanced tree.

--------------------------------------------------

Pattern Used:
Tree DFS / Inorder Traversal (Left → Root → Right)

Key Learning:

1. Inorder = Left → Root → Right. Memorize all three orders.
2. For BST problems, inorder traversal gives sorted order —
   this simplifies many problems significantly.
3. The recursive helper pattern (separate function + reference
   to result vector) is the cleanest way to implement traversals.
4. Iterative inorder uses a stack and is worth knowing as an
   alternative O(1) space approach (excluding stack).
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

    // Helper: performs inorder traversal recursively
    void inorder(TreeNode* root, vector<int>& ans)
    {
        // Base case: empty node
        if(root == NULL) return;

        // Step 1: Traverse left subtree
        inorder(root->left, ans);

        // Step 2: Visit current node
        ans.push_back(root->val);

        // Step 3: Traverse right subtree
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;

        inorder(root, ans);

        return ans;
    }
};
