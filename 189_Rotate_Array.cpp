/*
Problem 189. Rotate Array

Problem Statement:
Given an integer array nums, rotate the array to the right by k steps,
where k is non-negative.

Intuition:
Instead of shifting elements one by one (O(n*k)), we use array reversal
to achieve the rotation in O(n) time.

Key Idea:
Rotation can be broken into three reversals:

1. Reverse entire array
2. Reverse first k elements
3. Reverse remaining n-k elements

This reorders elements into correct rotated positions.

Approach:
1. Compute k = k % n (handle k > n cases)
2. Reverse whole array
3. Reverse first k elements
4. Reverse remaining elements

Example:

Input:
nums = [1,2,3,4,5,6,7], k = 3

Step 1: reverse whole array
[7,6,5,4,3,2,1]

Step 2: reverse first k elements
[5,6,7,4,3,2,1]

Step 3: reverse remaining elements
[5,6,7,1,2,3,4]

Output:
[5,6,7,1,2,3,4]

Why This Works:
Reversing rearranges relative order in a controlled way.
We first move last k elements to front (via full reverse),
then fix order within both partitions.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Array Manipulation / Reversal Trick

Key Learning:
Many rotation/reordering problems can be solved using reverse operations
instead of shifting elements.
*/



class Solution {
public:

    void rotate(vector<int>& nums, int k) {

        // Size of array
        int n = nums.size();

        // Normalize k (handle k > n cases)
        k = k % n;

        // Step 1: Reverse entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};
