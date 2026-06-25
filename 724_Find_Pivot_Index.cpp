/*
Problem 724. Find Pivot Index

Problem Statement:
Given an array of integers nums, return the leftmost pivot index.

The pivot index is the index where the sum of all numbers strictly
to the left equals the sum of all numbers strictly to the right.

If no such index exists, return -1.
If the index is on the left edge, the left sum is 0.
If the index is on the right edge, the right sum is 0.

--------------------------------------------------

Intuition:

A brute force approach computes left sum and right sum for every
index using two nested loops — O(n²).

We can do this in O(n) using a prefix sum observation:

At any index i:
    leftSum  = sum of nums[0..i-1]
    rightSum = totalSum - leftSum - nums[i]

So we only need the total sum precomputed once.

--------------------------------------------------

Key Idea:

Precompute totalSum.

For each index i, check:
    leftSum == totalSum - leftSum - nums[i]

Which simplifies to:
    leftSum == rightSum

If true → return i.
Otherwise add nums[i] to leftSum and move forward.

--------------------------------------------------

Approach:

1. Compute totalSum = sum of all elements.
2. Initialize leftSum = 0.
3. For each index i:
   - Check if leftSum == totalSum - leftSum - nums[i]
   - If yes → return i (pivot found)
   - Otherwise → leftSum += nums[i]
4. Return -1 if no pivot found.

--------------------------------------------------

Example:

nums = [1, 7, 3, 6, 5, 6]

totalSum = 28

i=0: left=0, right=28-0-1=27  → 0 != 27
i=1: left=1, right=28-1-7=20  → 1 != 20
i=2: left=8, right=28-8-3=17  → 8 != 17
i=3: left=11, right=28-11-6=11 → 11 == 11 → return 3

Output: 3

--------------------------------------------------

Why This Works:

At every index, right sum is derivable from total sum and
current left sum without a second array or nested loop.

The condition leftSum == totalSum - leftSum - nums[i] is
mathematically equivalent to leftSum == rightSum.

--------------------------------------------------

Time Complexity: O(n)

Two linear passes — one for total sum, one for checking pivots.

--------------------------------------------------

Space Complexity: O(1)

Only two integer variables used.

--------------------------------------------------

Pattern Used:
Prefix Sum / Running Sum

Key Learning:

1. rightSum = totalSum - leftSum - nums[i] eliminates the need
   for a suffix sum array entirely.
2. This running-sum pattern is one of the most versatile
   array techniques — also used in Subarray Sum Equals K.
3. Always check the pivot condition BEFORE updating leftSum,
   not after — order matters here.
*/



class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        // Step 1: Compute total sum of array
        int sum = 0;

        for(int x : nums)
        {
            sum += x;
        }

        // Step 2: Track running left sum
        int leftsum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            // Right sum = total - left sum - current element
            // Check if left sum equals right sum
            if(leftsum == sum - leftsum - nums[i])
            {
                return i;
            }

            // Update left sum for next iteration
            leftsum += nums[i];
        }

        // No pivot index found
        return -1;
    }
};
