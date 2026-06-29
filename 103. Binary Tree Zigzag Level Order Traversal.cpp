/*
Problem 103. Binary Tree Zigzag Level Order Traversal

Problem Statement:

Given the root of a binary tree, return the zigzag level order traversal
of its nodes' values.

The traversal should visit the tree level by level, but alternate the
direction at each level:

- First level: Left to Right
- Second level: Right to Left
- Third level: Left to Right
- and so on.

--------------------------------------------------

Intuition:

A normal level order traversal (BFS) already processes the tree one
level at a time.

The only difference is that every alternate level must be reversed.

Instead of changing the traversal itself, we can:

1. Perform a standard BFS.
2. Store all nodes of the current level.
3. Reverse the level whenever required.

This keeps the implementation simple and easy to understand.

--------------------------------------------------

Key Idea:

Step 1: Use a queue to perform level-order traversal.
Step 2: Process one level at a time.
Step 3: Store all node values of the current level.
Step 4: Reverse the level if it is an odd-numbered level.
Step 5: Toggle the direction for the next level.

--------------------------------------------------

Approach:

1. If the tree is empty, return an empty result.
2. Push the root into a queue.
3. Maintain a boolean variable `reverseLevel`.
4. While the queue is not empty:
   - Determine the number of nodes in the current level.
   - Process exactly those nodes.
   - Store their values in a vector.
   - Push their children into the queue.
5. If `reverseLevel` is true:
   - Reverse the current level.
6. Add the level to the final answer.
7. Toggle `reverseLevel`.
8. Return the result.

--------------------------------------------------

Example:

Tree:

        3
      /   \
     9     20
          /  \
         15   7

Level 1:

[3]

Direction:
Left → Right

Result:

[[3]]

------------------

Level 2:

[9,20]

Reverse:

[20,9]

Result:

[[3],[20,9]]

------------------

Level 3:

[15,7]

Direction:
Left → Right

Result:

[[3],[20,9],[15,7]]

--------------------------------------------------

Counter Example:

Tree:

NULL

The tree contains no nodes.

Output:

[]

--------------------------------------------------

Why This Works:

Breadth-First Search naturally visits nodes level by level.

Each iteration processes exactly one level.

Reversing every alternate level changes only the output order,
without affecting the traversal itself.

The boolean flag keeps track of whether the current level should
be reversed.

--------------------------------------------------

Time Complexity: O(n)

Every node is visited exactly once.

Although some levels are reversed, the total cost of all reversals
across the tree is still O(n).

--------------------------------------------------

Space Complexity: O(n)

- The queue may store an entire level of the tree.
- The result vector stores every node exactly once.

--------------------------------------------------

Pattern Used:
Binary Tree / Breadth-First Search (BFS) / Level Order Traversal

Key Learning:

1. BFS is the standard technique for level-order traversal.
2. Process one complete level at a time using the queue's current size.
3. A simple boolean flag can alternate behavior between consecutive levels.
4. Sometimes modifying the output (reversing a level) is easier than modifying the traversal itself.
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if(root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        bool reverseLevel = false;

        while(!q.empty())
        {
            vector<int> level;

            int levelSize = q.size();

            // Process one level
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            // Reverse every alternate level
            if(reverseLevel)
                reverse(level.begin(), level.end());

            result.push_back(level);

            reverseLevel = !reverseLevel;
        }

        return result;
    }
};
