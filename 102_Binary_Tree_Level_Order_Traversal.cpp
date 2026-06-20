/*
Problem 102. Binary Tree Level Order Traversal

Problem Statement:
Given the root of a binary tree, return the level order traversal
of its nodes' values.

(Level order traversal means visiting nodes level by level from left to right.)

Intuition:
Since we need to process nodes level by level, a queue is the perfect
data structure because it follows FIFO (First In First Out).

We process all nodes of the current level before moving to the next level.

Key Idea:
Use Breadth First Search (BFS).

At each iteration:
- Store the current queue size (number of nodes in this level)
- Process exactly those nodes
- Add their children to the queue
- Store the current level's values

Approach:
1. Handle edge case when root is NULL.
2. Create a queue and push root into it.
3. While queue is not empty:
   a. Get current level size.
   b. Traverse all nodes of that level.
   c. Store their values.
   d. Push their children into the queue.
4. Add current level to result.
5. Return result.

Example:

        3
       / \
      9  20
         / \
        15  7

Level 0: [3]
Level 1: [9,20]
Level 2: [15,7]

Output:
[[3],[9,20],[15,7]]

Why This Works:
The queue always contains nodes of the upcoming levels.
By processing exactly 'levelsize' nodes each iteration,
we ensure nodes are grouped correctly level by level.

Time Complexity: O(n)

Space Complexity: O(n)

Pattern Used:
Breadth First Search (BFS)

Key Learning:
Whenever a tree problem asks for:
- Level by level traversal
- Shortest path
- Nearest node

Think BFS with a queue.
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        // Stores final level order traversal
        vector<vector<int>> result;

        // Edge case: empty tree
        if(root == nullptr)
            return result;

        // Queue used for BFS traversal
        queue<TreeNode*> q;

        // Start BFS from root
        q.push(root);

        // Continue until all nodes are processed
        while(!q.empty())
        {
            // Stores values of current level
            vector<int> level;

            // Number of nodes present in current level
            int levelsize = q.size();

            // Process exactly one level
            for(int i = 0; i < levelsize; i++)
            {
                // Get front node
                TreeNode* node = q.front();
                q.pop();

                // Store node value
                level.push_back(node->val);

                // Push left child for next level
                if(node->left)
                    q.push(node->left);

                // Push right child for next level
                if(node->right)
                    q.push(node->right);
            }

            // Store completed level
            result.push_back(level);
        }

        return result;
    }
};
