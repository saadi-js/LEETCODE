/*
Problem 27. Remove Element

Problem Statement:

Given an integer array nums and an integer val, remove all occurrences of val
in-place and return the new length of the array.

The order of elements may be changed, and elements beyond the returned length
are irrelevant.

--------------------------------------------------

Intuition:

We need to "filter out" all occurrences of a given value.

Instead of deleting elements (which is expensive in arrays),
we overwrite unwanted elements by shifting valid ones forward.

--------------------------------------------------

Key Idea:

We maintain a write pointer (ans):

- It tracks where the next valid element should go.
- We scan the array with i.

If nums[i] != val:
    we copy nums[i] to nums[ans]
    increment ans

This effectively compacts the array.

--------------------------------------------------

Approach:

1. Initialize ans = 0
2. Traverse array using i:
   - If nums[i] is not equal to val:
       → place it at nums[ans]
       → increment ans
3. Return ans as new length

--------------------------------------------------

Example:

nums = [3,2,2,3], val = 3

Step-by-step:

i=0 → 3 (skip)
i=1 → 2 → keep → [2,_,_,_] ans=1
i=2 → 2 → keep → [2,2,_,_] ans=2
i=3 → 3 (skip)

Result length = 2, array = [2,2]

--------------------------------------------------

Why This Works:

We do not care about preserving removed elements.

We only ensure:
- All valid elements are moved forward
- Relative order of kept elements is preserved

--------------------------------------------------

Time Complexity: O(n)

Single pass through array.

--------------------------------------------------

Space Complexity: O(1)

In-place modification only.

--------------------------------------------------

Pattern Used:
Two Pointers (Filtering / In-place overwrite)

Key Learning:

1. Use a write pointer for in-place filtering problems.
2. Avoid deletion operations in arrays.
3. Same pattern as "move zeroes" and "remove duplicates".
*/



class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // ans acts as write pointer for valid elements
        int ans = 0;

        // Traverse entire array
        for(int i = 0; i < nums.size(); i++)
        {
            // If current element is not the value to remove
            if(nums[i] != val)
            {
                // Keep the element at write position
                nums[ans] = nums[i];

                // Move write pointer forward
                ans++;
            }
        }

        // ans is the new length of valid array
        return ans;
    }
};
