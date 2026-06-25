/*
Problem 1929. Concatenation of Array

Problem Statement:
Given an integer array nums of length n, return the array ans of
length 2n such that ans = [nums, nums] (nums concatenated with itself).

--------------------------------------------------

Intuition:

We need to place each element of nums at two positions:
- Its original index i
- Its shifted index i + n

This can be done in a single pass without any library functions.

--------------------------------------------------

Key Idea:

For every index i in nums:
- ans[i]     = nums[i]   → first copy
- ans[i + n] = nums[i]   → second copy

Both assignments happen in the same loop iteration,
making it a clean single-pass solution.

--------------------------------------------------

Approach:

1. Create ans array of size 2n initialized to 0.
2. For each i from 0 to n-1:
   - ans[i]     = nums[i]
   - ans[i + n] = nums[i]
3. Return ans.

--------------------------------------------------

Example:

nums = [1, 2, 1]
n = 3

ans[0] = 1, ans[3] = 1
ans[1] = 2, ans[4] = 2
ans[2] = 1, ans[5] = 1

Output: [1, 2, 1, 1, 2, 1]

--------------------------------------------------

Why This Works:

The index offset of n perfectly maps the second copy positions.
Since both copies are identical, reading from the same source
index for both placements is correct by definition.

--------------------------------------------------

Time Complexity: O(n)

Single pass through the array.

--------------------------------------------------

Space Complexity: O(1)

Excluding the output array.

--------------------------------------------------

Pattern Used:
Array / Index Mapping

Key Learning:

1. When duplicating arrays, index offset (i + n) maps positions cleanly.
2. Both writes in the same loop iteration keeps the code concise.
3. Pre-allocating the result array with the correct size avoids
   repeated memory reallocation from push_back.
*/



class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        // Size of original array
        int n = nums.size();

        // Result array of size 2n
        vector<int> ans(2 * n, 0);

        // Fill both copies in a single pass
        for(int i = 0; i < n; i++)
        {
            // First copy at original index
            ans[i] = nums[i];

            // Second copy at offset index
            ans[i + n] = nums[i];
        }

        return ans;
    }
};
