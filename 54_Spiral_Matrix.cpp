/*
Problem 54. Spiral Matrix

Problem Statement:
Given an m x n matrix, return all elements of the matrix in spiral order.

Spiral order means traversing the matrix in a clockwise direction:
left to right → top to bottom → right to left → bottom to top
then shrinking the boundaries and repeating.

--------------------------------------------------

Intuition:

A brute force approach might use a visited array and change
direction when hitting a boundary or visited cell.

Instead, we can simulate the spiral directly by maintaining
four boundaries that shrink after each layer is processed.

--------------------------------------------------

Key Idea:

Maintain four boundary pointers:
- srow (start row)    → top boundary
- erow (end row)      → bottom boundary
- scol (start column) → left boundary
- ecol (end column)   → right boundary

At each iteration, traverse the four sides of the current
boundary in order, then shrink all four boundaries inward.

--------------------------------------------------

Approach:

While srow <= erow AND scol <= ecol:

1. Top row → traverse left to right (srow, scol to ecol)
2. Right column → traverse top to bottom (scol+1 to erow, ecol)
3. Bottom row → traverse right to left (erow, ecol-1 to scol)
   BUT only if srow != erow (avoid re-traversing single row)
4. Left column → traverse bottom to top (erow-1 to srow+1, scol)
   BUT only if scol != ecol (avoid re-traversing single column)

Then shrink:
   srow++, scol++, erow--, ecol--

--------------------------------------------------

Example:

matrix =
[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]

Layer 1:
Top:    1 2 3
Right:  6 9
Bottom: 8 7
Left:   4

Layer 2 (single element):
Center: 5

Output: [1,2,3,6,9,8,7,4,5]

--------------------------------------------------

Why the Guard Conditions?

When only one row remains (srow == erow):
The bottom traversal would re-traverse the same row backwards.
So we skip it.

When only one column remains (scol == ecol):
The left traversal would re-traverse the same column.
So we skip it.

--------------------------------------------------

Time Complexity: O(m × n)

Every element is visited exactly once.

--------------------------------------------------

Space Complexity: O(1)

Excluding the output array, only boundary pointers are used.

--------------------------------------------------

Pattern Used:
Matrix Simulation / Layer-by-Layer Boundary Shrinking

Key Learning:

1. Spiral traversal = four directional passes + shrink boundaries.
2. Guard conditions prevent double-counting in single row/column cases.
3. The same boundary shrinking pattern applies to problems like
   Rotate Image and Set Matrix Zeroes.
4. Always handle edge cases: single row matrix, single column matrix.
*/



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // Matrix dimensions
        int m = matrix.size();
        int n = matrix[0].size();

        // Boundary pointers
        int srow = 0, scol = 0;
        int erow = m - 1, ecol = n - 1;

        // Result array
        vector<int> ans;

        // Process layer by layer
        while(srow <= erow && scol <= ecol)
        {
            // Step 1: Traverse top row left to right
            for(int i = scol; i <= ecol; i++)
            {
                ans.push_back(matrix[srow][i]);
            }

            // Step 2: Traverse right column top to bottom
            for(int i = srow + 1; i <= erow; i++)
            {
                ans.push_back(matrix[i][ecol]);
            }

            // Step 3: Traverse bottom row right to left
            // Guard: skip if only one row remains
            for(int i = ecol - 1; i >= scol; i--)
            {
                if(srow == erow) break;
                ans.push_back(matrix[erow][i]);
            }

            // Step 4: Traverse left column bottom to top
            // Guard: skip if only one column remains
            for(int i = erow - 1; i >= srow + 1; i--)
            {
                if(scol == ecol) break;
                ans.push_back(matrix[i][scol]);
            }

            // Shrink boundaries inward
            srow++;
            scol++;
            erow--;
            ecol--;
        }

        return ans;
    }
};
