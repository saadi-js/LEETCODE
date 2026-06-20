/*
Problem 199. Binary Tree Right Side View

Problem Statement:
Given the root of a binary tree, imagine yourself standing on the right side
of it. Return the values of the nodes you can see ordered from top to bottom.

Intuition:
When viewing a tree from the right side, only the rightmost node at each level
is visible.

Since we need information level-by-level, BFS (Level Order Traversal) is a
natural choice.

Key Idea:
Perform a level order traversal and record the last node encountered at every level.

Since nodes are processed left-to-right within a level:
- The last node processed in a level is the rightmost node.
- That node will be visible from the right side.

Approach:
1. Handle the empty tree case.
2. Use a queue for BFS.
3. Process one level at a time.
4. For every level:
   - Traverse all nodes of that level.
   - When processing the last node of the level,
     store its value in the answer.
5. Push children into the queue for the next level.
6. Return the collected right-side view.

Example:

        1
       / \
      2   3
       \   \
        5   4

Level 0 → [1]      → visible = 1
Level 1 → [2,3]    → visible = 3
Level 2 → [5,4]    → visible = 4

Output:
[1,3,4]

Why This Works:
At each level, the last node processed is the rightmost node.
Collecting these nodes gives exactly the right-side view.

Time Complexity: O(n)

Space Complexity: O(n)

Pattern Used:
Breadth First Search (Level Order Traversal)

Key Learning:
Many "view" problems in trees are solved by identifying a special node
(leftmost, rightmost, first, last) at each BFS level.
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
    vector<int> rightSideView(TreeNode* root) {

        // Stores the visible nodes from the right side
        vector<int> result;

        // Edge case: empty tree
        if(root == nullptr)
            return result;

        // Queue used for BFS traversal
        queue<TreeNode*> q;

        // Start traversal from root
        q.push(root);

        // Continue while there are nodes to process
        while(!q.empty())
        {
            // Number of nodes at current level
            int levelsize = q.size();

            // Process all nodes of current level
            for(int i = 0; i < levelsize; i++)
            {
                // Get front node
                TreeNode* node = q.front();
                q.pop();

                // Last node of the level is visible from right side
                if(i == levelsize - 1)
                {
                    result.push_back(node->val);
                }

                // Add left child to queue
                if(node->left)
                    q.push(node->left);

                // Add right child to queue
                if(node->right)
                    q.push(node->right);
            }
        }

        // Return right side view
        return result;
    }
};
