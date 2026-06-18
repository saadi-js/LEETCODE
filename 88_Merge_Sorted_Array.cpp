/*
Problem 88. Merge Sorted Array

Problem Statement:

You are given two sorted integer arrays A and B, and two integers m and n
representing the number of valid elements in A and B respectively.

Merge B into A as one sorted array.

A has a size of m + n, where the last n elements are initialized to 0
and should be ignored during merging.

--------------------------------------------------

Intuition:

A naive approach would be:

- Copy B into A
- Sort A

This would take O((m+n) log(m+n)).

But since both arrays are already sorted, we can do better.

--------------------------------------------------

Key Idea:

We use a two-pointer approach from the end of the arrays.

Why from the end?

Because A has extra space at the end, so we can safely overwrite it
without losing useful data.

--------------------------------------------------

Approach:

1. Set three pointers:
   - i = m - 1 → last valid element in A
   - j = n - 1 → last element in B
   - idx = m + n - 1 → last position in A

2. Compare elements from the end:
   - If A[i] > B[j]:
        place A[i] at idx
        move i and idx backward
   - Else:
        place B[j] at idx
        move j and idx backward

3. If elements remain in B:
   copy them into A (because A may be exhausted first)

4. If A elements remain:
   they are already in correct place, so no action needed

--------------------------------------------------

Example:

A = [1,3,5,0,0,0]
B = [2,4,6]

Step-by-step:

Compare from back:
5 vs 6 → put 6
5 vs 4 → put 5
3 vs 4 → put 4
3 vs 2 → put 3
1 vs 2 → put 2
remaining 1 already in place

Result:
[1,2,3,4,5,6]

--------------------------------------------------

Why This Works:

We fill A from the back to avoid overwriting unprocessed values.

If we started from the front, we would lose original values of A.

--------------------------------------------------

Time Complexity: O(m + n)

Each element is processed once.

--------------------------------------------------

Space Complexity: O(1)

No extra array is used.

--------------------------------------------------

Pattern Used:
Two Pointers (Backward Traversal)

Key Learning:

1. When an array has extra space at the end, always consider
   filling from back to front.
2. Prevents overwriting useful data.
3. Very common pattern in merge-type problems.
*/



class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {

        // Pointer to last position of merged array
        int idx = m + n - 1;

        // Pointer to last valid element in A
        int i = m - 1;

        // Pointer to last element in B
        int j = n - 1;

        // Merge while both arrays have elements
        while (i >= 0 && j >= 0)
        {
            // If current element of A is larger
            if (A[i] > B[j])
            {
                // Place A[i] at correct position
                A[idx] = A[i];
                idx--;
                i--;
            }
            else
            {
                // Place B[j] at correct position
                A[idx] = B[j];
                idx--;
                j--;
            }
        }

        // If elements remain in B, copy them
        // (A elements are already in correct position)
        while (j >= 0)
        {
            A[idx] = B[j];
            idx--;
            j--;
        }
    }
};
