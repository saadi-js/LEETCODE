/*
Problem 53. Maximum Subarray

Problem Statement:

Given an integer array nums, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

--------------------------------------------------

Intuition:

A brute force approach checks all subarrays:
- Generate all subarrays
- Compute their sums
- Track maximum

This is O(n²) or O(n³).

We need an optimal O(n) solution.

--------------------------------------------------

Key Idea (Kadane’s Algorithm):

At each index, we decide:

- Do we extend the previous subarray?
- Or start a new subarray from current element?

If current running sum becomes negative, it is better to discard it,
because it will only reduce future sums.

--------------------------------------------------

Approach:

1. Maintain two variables:
   - curr_sum → current subarray sum
   - maxsum → best sum found so far

2. Traverse array:
   - Add current element to curr_sum
   - Update maxsum if curr_sum is larger
   - If curr_sum becomes negative → reset it to 0

3. Return maxsum

--------------------------------------------------

Example:

nums = [-2,1,-3,4,-1,2,1,-5,4]

Step-by-step:

curr_sum = 0

-2 → curr_sum = -2 → reset
1 → curr_sum = 1
-3 → curr_sum = -2 → reset
4 → curr_sum = 4
-1 → curr_sum = 3
2 → curr_sum = 5
1 → curr_sum = 6 (max)
-5 → curr_sum = 1
4 → curr_sum = 5

Answer = 6

--------------------------------------------------

Why This Works:

A negative running sum cannot help future subarrays,
so we discard it and start fresh.

This greedy decision ensures optimal substructure.

--------------------------------------------------

Time Complexity: O(n)

Single pass through array.

--------------------------------------------------

Space Complexity: O(1)

Only two variables used.

--------------------------------------------------

Pattern Used:
Kadane’s Algorithm (Dynamic Programming / Greedy Hybrid)

Key Learning:

1. If prefix becomes harmful (negative), reset it.
2. At each step, maintain best possible subarray ending here.
3. One of the most important DP-like greedy patterns.
*/




class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // maxsum stores the best subarray sum found so far
        int maxsum = INT_MIN;

        // curr_sum stores current running subarray sum
        int curr_sum = 0;

        // Traverse all elements
        for(int i = 0; i < nums.size(); i++)
        {
            // Add current element to running sum
            curr_sum = curr_sum + nums[i];

            // Update maximum sum if needed
            maxsum = max(curr_sum, maxsum);

            // If running sum becomes negative,
            // discard it (start fresh from next element)
            if(curr_sum < 0)
            {
                curr_sum = 0;
            }
        }

        // Return maximum subarray sum
        return maxsum;
    }
};
