/*
Problem 2149. Rearrange Array Elements by Sign

Problem Statement:

You are given a 0-indexed integer array nums of even length.

The array contains an equal number of positive and negative integers.

Rearrange the array such that:
- Positive and negative numbers alternate
- The relative order of positives and negatives is preserved
- Start with a positive number

Return the rearranged array.

--------------------------------------------------

Intuition:

We need to place:
- Positive numbers at even indices (0, 2, 4, ...)
- Negative numbers at odd indices (1, 3, 5, ...)

Since positives and negatives are equal in count,
we can directly assign them to their correct positions.

--------------------------------------------------

Key Idea:

Instead of shuffling in-place, we construct a new array:

- pos pointer → tracks next even index for positive numbers
- neg pointer → tracks next odd index for negative numbers

As we traverse the input array:
- Place positive numbers at pos
- Place negative numbers at neg

--------------------------------------------------

Approach:

1. Create result array of same size.
2. Initialize:
   - pos = 0 (first even index)
   - neg = 1 (first odd index)
3. Traverse nums:
   - If positive → place at pos, increment pos by 2
   - If negative → place at neg, increment neg by 2
4. Return result array.

--------------------------------------------------

Example:

nums = [3,1,-2,-5,2,-4]

Step-by-step:

Positive → 3, 1, 2
Negative → -2, -5, -4

Result:
[3, -2, 1, -5, 2, -4]

--------------------------------------------------

Why This Works:

Constraints guarantee equal number of positive and negative values,
so:
- Every even index is reserved for positives
- Every odd index is reserved for negatives

This avoids backtracking or swapping.

--------------------------------------------------

Time Complexity: O(n)

Single pass through array.

--------------------------------------------------

Space Complexity: O(n)

Extra array used for rearrangement.

--------------------------------------------------

Pattern Used:
Index Placement / Two Pointers (Position Mapping)

Key Learning:

1. When output positions are predetermined, use direct indexing.
2. Separate pointers for different categories simplify logic.
3. Avoid in-place complexity when structure is fixed.
4. Common pattern in rearrangement problems.
*/




class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // Size of input array
        int n = nums.size();

        // Result array
        vector<int> ans(n);

        // Pointer for positive numbers (even indices)
        int pos = 0;

        // Pointer for negative numbers (odd indices)
        int neg = 1;

        // Traverse input array
        for(int i = 0; i < nums.size(); i++)
        {
            // If element is positive
            if(nums[i] > 0)
            {
                ans[pos] = nums[i];
                pos += 2;
            }
            else
            {
                // If element is negative
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};



