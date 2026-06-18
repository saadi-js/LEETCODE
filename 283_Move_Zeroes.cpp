/*
Problem 283. Move Zeroes

Problem Statement:

Given an integer array nums, move all 0's to the end of it while maintaining
the relative order of the non-zero elements.

You must do this in-place without making a copy of the array.

--------------------------------------------------

Intuition:

A naive approach would be:
- Create a new array
- Copy all non-zero elements
- Fill remaining positions with zeros

This uses extra space O(n).

We want an in-place solution.

--------------------------------------------------

Key Idea:

We use a two-pointer technique:

- j → tracks the position where the next non-zero element should go
- i → scans the array

Whenever we find a non-zero element:
- Swap it with nums[j]
- Move j forward

This ensures:
- All non-zero elements are pushed to the front
- All zeros naturally move to the back

--------------------------------------------------

Approach:

1. Initialize j = 0
2. Traverse array using i:
   - If nums[i] != 0:
        swap nums[i] and nums[j]
        increment j
3. Continue until end of array

--------------------------------------------------

Example:

nums = [0,1,0,3,12]

Step-by-step:

i=0 → 0 → skip
i=1 → 1 → swap → [1,0,0,3,12]
i=2 → 0 → skip
i=3 → 3 → swap → [1,3,0,0,12]
i=4 → 12 → swap → [1,3,12,0,0]

Result = [1,3,12,0,0]

--------------------------------------------------

Why This Works:

We maintain a boundary (j) that separates:
- Left side → all non-zero elements
- Right side → all zeros

Each non-zero element is placed in correct order.

--------------------------------------------------

Time Complexity: O(n)

Single pass through array.

--------------------------------------------------

Space Complexity: O(1)

In-place swapping only.

--------------------------------------------------

Pattern Used:
Two Pointers (Partitioning Technique)

Key Learning:

1. Think of zero-move problems as partitioning problems.
2. Maintain a boundary index for valid elements.
3. Swap ensures order preservation.
4. Very common in array rearrangement problems.
*/



class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // j tracks position for next non-zero element
        int j = 0;

        // Traverse the array
        for(int i = 0; i < nums.size(); i++)
        {
            // If current element is non-zero
            if(nums[i] != 0)
            {
                // Swap it to the correct position
                swap(nums[i], nums[j]);

                // Move boundary forward
                j++;
            }
        }
    }
};
