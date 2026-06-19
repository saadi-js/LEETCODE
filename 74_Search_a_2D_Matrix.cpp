/*
Problem 74. Search a 2D Matrix

Problem Statement:
You are given an m x n integer matrix where:
1. Each row is sorted in ascending order
2. The first integer of each row is greater than the last integer of the previous row

Given a target, return true if it exists in the matrix, otherwise false.

Intuition:
The matrix behaves like a flattened sorted array.

We first identify the correct row using binary search,
then perform another binary search inside that row.

Key Idea:
Two-level binary search:
1. Binary search on rows to find candidate row
2. Binary search within that row

Approach:
1. Use binary search on rows:
   - Check if target lies between first and last element of row
   - If yes → search inside row
   - Else decide upper/lower half

2. For selected row:
   - Perform standard binary search

3. Return true if found, else false.

Example:
matrix =
[
 [1, 3, 5, 7],
 [10,11,16,20],
 [23,30,34,60]
]

target = 16
→ found in second row

Why This Works:
Matrix structure guarantees global sorted order when rows are viewed sequentially.

Time Complexity: O(log m + log n)
Space Complexity: O(1)

Pattern Used:
Binary Search on Rows + Binary Search on Columns

Key Learning:
When structure is "row-wise sorted + row boundaries sorted":
→ Use double binary search
*/



class Solution {
public:

    // Binary search inside a specific row
    bool searchINrow(vector<vector<int>>& matrix, int target, int row)
    {
        int n = matrix[0].size();

        // Column boundaries
        int start = 0;
        int end = n - 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            // Target found
            if(target == matrix[row][mid])
            {
                return true;
            }

            // Search right half
            else if(target > matrix[row][mid])
            {
                start = mid + 1;
            }

            // Search left half
            else
            {
                end = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();      // number of rows
        int n = matrix[0].size();   // number of columns

        // Binary search on rows
        int start = 0;
        int end = m - 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            // Check if target lies within this row's range
            if(target >= matrix[mid][0] && target <= matrix[mid][n - 1])
            {
                // Search inside this row
                return searchINrow(matrix, target, mid);
            }

            // Target is in lower rows
            else if(target > matrix[mid][n - 1])
            {
                start = mid + 1;
            }

            // Target is in upper rows
            else
            {
                end = mid - 1;
            }
        }

        return false;
    }
};

