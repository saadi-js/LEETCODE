/*
Problem 111. Minimum Depth of Binary Tree

Problem Statement:

Given the root of a binary tree, return its minimum depth.

The minimum depth is the number of nodes along the shortest path
from the root node down to the nearest leaf node.

A leaf node is a node with no left and no right child.

--------------------------------------------------

Intuition:

The minimum depth depends on the shortest path from the root to a leaf.

A recursive solution works naturally because the minimum depth of a tree
depends on the minimum depth of its left and right subtrees.

However, there is one important edge case:

If one child is NULL, we cannot simply take the minimum of the two depths,
because the NULL child does not represent a valid path to a leaf.
Instead, we must continue through the existing child.

--------------------------------------------------

Key Idea:

Step 1: If the tree is empty, its depth is 0.
Step 2: If the current node is a leaf, its depth is 1.
Step 3: If only one subtree exists, recursively compute the depth of that subtree.
Step 4: If both subtrees exist, take the minimum of their depths and add 1.

--------------------------------------------------

Approach:

1. If the root is NULL, return 0.
2. If the current node is a leaf, return 1.
3. If the left child is NULL:
   - Return 1 + minimum depth of the right subtree.
4. If the right child is NULL:
   - Return 1 + minimum depth of the left subtree.
5. Otherwise:
   - Compute the minimum depth of both subtrees.
   - Return the smaller depth + 1 for the current node.

--------------------------------------------------

Example:

Tree:

        3
       / \
      9   20
         /  \
        15   7

Depths:

Left subtree = 1
Right subtree = 2

Minimum depth = 1 + min(1, 2)
               = 2

Output:
2

--------------------------------------------------

Counter Example:

Tree:

        1
         \
          2
           \
            3

Incorrect approach:
min(0, 2) + 1 = 1 ❌

Correct approach:

Since the left subtree is NULL,
we must continue through the right subtree.

Depth = 1 + 2 = 3

Output:
3

--------------------------------------------------

Why This Works:

Every recursive call computes the minimum depth of its subtree.

Special handling of nodes with only one child ensures that we never
consider an invalid NULL path as the shortest path.

When both children exist, taking the minimum correctly identifies the
nearest leaf.

--------------------------------------------------

Time Complexity: O(n)

Every node is visited exactly once.

--------------------------------------------------

Space Complexity: O(h)

Where h is the height of the tree.

In the worst case (skewed tree), h = n.
In a balanced tree, h = log n.

--------------------------------------------------

Pattern Used:
Binary Tree / Depth-First Search (DFS) / Recursion

Key Learning:

1. In tree problems, always identify the base cases before writing recursion.
2. For minimum depth, a NULL child cannot be treated as a valid path.
3. Handle the "single child" case separately before taking the minimum.
4. Recursive tree solutions often combine answers from left and right subtrees.
*/

class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        if(root->left == NULL && root->right == NULL)
            return 1;

        if(root->left == NULL)
        {
            return 1 + minDepth(root->right);
        }

        if(root->right == NULL)
        {
            return 1 + minDepth(root->left);
        }

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
