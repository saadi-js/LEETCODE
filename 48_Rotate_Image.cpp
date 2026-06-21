/*
Problem 48. Rotate Image

Problem Statement:
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees clockwise, in-place.

You must do this without allocating a new 2D array.

--------------------------------------------------

Intuition:

A direct simulation would require placing every element into
a new matrix at its rotated position.

But we need to do this in-place.

Observing the effect of a 90-degree clockwise rotation:

element at (i, j) → goes to (j, n-1-i)

Instead of tracking this directly, we break the rotation into
two simpler operations that together produce the same result.

--------------------------------------------------

Key Idea:

A 90-degree clockwise rotation = Transpose + Reverse each row.

Step 1: Transpose the matrix
    Swap matrix[i][j] with matrix[j][i]
    This flips the matrix along the main diagonal.

Step 2: Reverse each row
    This handles the horizontal flip needed to complete the rotation.

--------------------------------------------------

Why This Works:

Original:
1 2 3
4 5 6
7 8 9

After Transpose:
1 4 7
2 5 8
3 6 9

After Reversing each row:
7 4 1
8 5 2
9 6 3

This is exactly a 90-degree clockwise rotation.

--------------------------------------------------

Approach:

1. Transpose:
   - Iterate i from 0 to n-1
   - Iterate j from i+1 to n-1
   - Swap matrix[i][j] with matrix[j][i]
   - Note: j starts from i+1 to avoid double-swapping

2. Reverse each row:
   - For every row, call reverse() on it

--------------------------------------------------

Example:

Input:
[[1,2,3],
 [4,5,6],
 [7,8,9]]

Output:
[[7,4,1],
 [8,5,2],
 [9,6,3]]

--------------------------------------------------

Time Complexity: O(n²)

Every element is visited once during transpose
and once during row reversal.

--------------------------------------------------

Space Complexity: O(1)

All operations are performed in-place.
No extra matrix is used.

--------------------------------------------------

Pattern Used:
Matrix Manipulation (Transpose + Reverse)

Key Learning:

1. Clockwise 90° rotation = Transpose + Reverse each row.
2. Counter-clockwise 90° rotation = Reverse each row + Transpose.
3. Breaking complex transformations into simpler steps is a
   very common matrix interview technique.
4. Always start j from i+1 during transpose to avoid undoing swaps.
*/



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // Dimensions of the square matrix
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Transpose the matrix
        // Swap elements across the main diagonal
        for(int i = 0; i < m; i++)
        {
            // j starts from i+1 to avoid re-swapping
            for(int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        // Converts transpose into clockwise rotation
        for(int i = 0; i < m; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
