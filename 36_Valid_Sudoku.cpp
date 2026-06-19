/*
Problem 36. Valid Sudoku

Problem Statement:
Determine if a 9×9 Sudoku board is valid. Only the filled cells need to be validated
according to Sudoku rules:
1. Each row must contain digits 1–9 without repetition.
2. Each column must contain digits 1–9 without repetition.
3. Each 3×3 sub-box must contain digits 1–9 without repetition.

Empty cells are represented by '.' and are ignored.

Intuition:
We need to ensure uniqueness constraints across three independent dimensions:
- Rows
- Columns
- 3×3 sub-boxes

Instead of repeatedly scanning rows/columns/boxes, we maintain sets that track
which values have already been seen.

Key Idea:
Use three arrays of hash sets:
- rows[9] → track digits in each row
- cols[9] → track digits in each column
- boxes[9] → track digits in each 3×3 box

For every filled cell, check whether the value already exists in any of these sets.

If yes → invalid Sudoku.
If no → insert into corresponding sets.

Approach:
1. Initialize:
   - unordered_set<char> rows[9]
   - unordered_set<char> cols[9]
   - unordered_set<char> boxes[9]

2. Traverse entire 9×9 board:
   - Skip '.' cells
   - Compute box index using:
     box_index = (r / 3) * 3 + (c / 3)

3. For each value:
   a. Check if already exists in row, column, or box set
   b. If yes → return false
   c. Otherwise insert into all three sets

4. If traversal completes → return true

Example:
If board has duplicate '5' in same row:
→ rows[r].count('5') triggers failure immediately

Why This Works:
Sudoku validity is purely about constraint satisfaction.
By tracking seen values in each constraint group, we ensure no rule is violated.

Each cell is processed once, and membership checks are O(1).

Time Complexity: O(81) → O(1) (fixed board size)
Space Complexity: O(1) (bounded 9×9 structure)

Pattern Used:
Constraint Checking using Hash Sets (Row/Column/Grid Tracking)

Key Learning:
Whenever a problem involves multiple independent uniqueness constraints:
→ Use separate hash structures per constraint dimension
*/




class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Track numbers seen in each row
        unordered_set<char> rows[9];

        // Track numbers seen in each column
        unordered_set<char> cols[9];

        // Track numbers seen in each 3x3 sub-box
        unordered_set<char> boxes[9];

        // Traverse each cell in the 9x9 board
        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                // Current cell value
                char val = board[r][c];

                // Skip empty cells
                if(val == '.') continue;

                // Compute index of 3x3 box
                int box_index = (r / 3) * 3 + (c / 3);

                // Check if value already exists in row, column, or box
                if(rows[r].count(val) ||
                   cols[c].count(val) ||
                   boxes[box_index].count(val))
                {
                    return false;
                }

                // Mark value as seen in row
                rows[r].insert(val);

                // Mark value as seen in column
                cols[c].insert(val);

                // Mark value as seen in box
                boxes[box_index].insert(val);
            }
        }

        // No violations found
        return true;
    }
};
