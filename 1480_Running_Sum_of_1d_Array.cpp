/*
Problem 1480. Running Sum of 1d Array

Problem Statement:
Given an array nums, return the running sum of nums.

The running sum at index i is defined as:
runningSum[i] = nums[0] + nums[1] + ... + nums[i]

Intuition:
Instead of recalculating the sum for every index (which would be inefficient),
we can reuse previously computed results.

Each position already contains partial information that can be extended forward.

Key Idea:
Use Prefix Sum In-Place.

For each index i:
- Add the value from previous index nums[i-1]
- This transforms nums into a prefix sum array

Approach:
1. Start from index 1 (since index 0 has no previous element).
2. Update each element as:
   nums[i] = nums[i] + nums[i - 1]
3. Return the modified array.

Example:
nums = [1,2,3,4]

Step-by-step:
i=1 → [1, 3, 3, 4]
i=2 → [1, 3, 6, 4]
i=3 → [1, 3, 6, 10]

Final output: [1, 3, 6, 10]

Why This Works:
Each element accumulates all previous values step by step.

Instead of recomputing sum each time, we reuse already computed prefix sum.

Time Complexity: O(n)
Space Complexity: O(1) (in-place modification)

Pattern Used:
Prefix Sum (In-place accumulation)

Key Learning:
Whenever a problem asks for cumulative sums or repeated range accumulation:
→ Think Prefix Sum
*/



class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        // Start from index 1 since index 0 has no previous sum
        for(int i = 1; i < nums.size(); i++)
        {
            // Add previous accumulated sum to current element
            nums[i] += nums[i - 1];
        }

        // Return modified array containing running sums
        return nums;
    }
};
