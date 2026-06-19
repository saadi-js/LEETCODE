/*
Problem 240. Search a 2D Matrix II

Problem Statement:
Write an efficient algorithm that searches for a target value in an m x n matrix.

The matrix has the following properties:
1. Each row is sorted in ascending order.
2. Each column is sorted in ascending order.

Return true if target exists, otherwise false.

Intuition:
Unlike the previous problem (74), we cannot binary search rows because the row boundaries do NOT guarantee global separation.

Instead, we exploit the sorted structure from both row and column directions.

Key Idea:
Start from the top-right corner:
- If current value == target → found
- If current value < target → move down (increase value)
- If current value > target → move left (decrease value)

This works because:
- Moving down increases values in column
- Moving left decreases values in row

So we eliminate one row or one column at each step.

Approach:
1. Start at top-right: (r = 0, c = n - 1)
2. While within bounds:
   a. If equal → return true
   b. If smaller → move down
   c. If larger → move left
3. If loop ends → return false

Example:
matrix =
[
 [1, 4, 7, 11],
 [2, 5, 8, 12],
 [3, 6, 9, 16],
 [10,13,14,17]
]

target = 5 → found

Why This Works:
Each comparison eliminates either a row or a column,
reducing search space from O(m*n) to O(m+n).

Time Complexity: O(m + n)
Space Complexity: O(1)

Pattern Used:
Matrix Search (Greedy Elimination from Corner)

Key Learning:
When both rows and columns are sorted:
→ start from a corner and eliminate search space intelligently
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Number of rows
        int m = matrix.size();

        // Number of columns
        int n = matrix[0].size();

        // Start from top-right corner
        int r = 0;
        int c = n - 1;

        // Traverse until we go out of bounds
        while(r < m && c >= 0)
        {
            // If element found
            if(target == matrix[r][c])
            {
                return true;
            }

            // If target is larger → move down
            else if(target > matrix[r][c])
            {
                r++;
            }

            // If target is smaller → move left
            else
            {
                c--;
            }
        }

        // Target not found
        return false;
    }
};
