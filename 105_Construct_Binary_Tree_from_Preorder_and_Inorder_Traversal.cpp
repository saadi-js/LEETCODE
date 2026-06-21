/*
Problem 105. Construct Binary Tree from Preorder and Inorder Traversal

Problem Statement:
Given two integer arrays preorder and inorder representing the traversal
of a binary tree, construct the binary tree and return its root.

Intuition:
We use the properties of traversal:

Preorder: Root → Left → Right
Inorder:  Left → Root → Right

So:
- Preorder tells us the root node (always first element)
- Inorder tells us left and right subtree boundaries

Key Idea:
1. Pick root from preorder
2. Find root in inorder array
3. Elements left of root → left subtree
4. Elements right of root → right subtree
5. Recurse

Approach:
1. Maintain a global preorder index (preidx)
2. For each recursive call:
   - Create root from preorder[preidx]
   - Find root position in inorder
   - Split inorder into left/right subtrees
3. Recursively build left and right subtrees

Example:

Preorder: [3,9,20,15,7]
Inorder:  [9,3,15,20,7]

Step:
Root = 3
Left inorder = [9]
Right inorder = [15,20,7]

Continue recursively...

Why This Works:
Preorder always gives correct root order,
and inorder defines structural boundaries.

Time Complexity: O(n^2) (due to linear search in inorder)
Space Complexity: O(n)

Pattern Used:
Tree Construction from Traversals (Divide & Conquer)

Key Learning:
Preorder = structure guide
Inorder = boundary guide
Combine both to reconstruct tree.
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

    // Linear search to find root index in inorder array
    int search(vector<int>& inorder, int left, int right, int val)
    {
        for(int i = left; i <= right; i++)
        {
            if(inorder[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    // Recursive helper to build tree
    TreeNode* helper(vector<int>& preorder,
                     vector<int>& inorder,
                     int &preidx,
                     int left,
                     int right)
    {
        // Base case: invalid range
        if(left > right) return NULL;

        // Create root from preorder
        TreeNode* root = new TreeNode(preorder[preidx]);

        // Find root in inorder to split tree
        int inidx = search(inorder, left, right, preorder[preidx]);

        // Move to next preorder element
        preidx++;

        // Build left subtree
        root->left = helper(preorder, inorder, preidx, left, inidx - 1);

        // Build right subtree
        root->right = helper(preorder, inorder, preidx, inidx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Start from first preorder element
        int preidx = 0;

        // Build tree using full inorder range
        return helper(preorder, inorder, preidx, 0, inorder.size() - 1);
    }
};
