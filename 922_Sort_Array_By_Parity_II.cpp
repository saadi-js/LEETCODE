/*
Problem 922. Sort Array By Parity II

Problem Statement:
Given an integer array nums of even length, where exactly half of the elements
are even and half are odd, return any valid arrangement such that:
- Even-indexed positions contain even numbers
- Odd-indexed positions contain odd numbers

Intuition:
We separate placement logic instead of sorting:
- Even numbers must go to even indices (0, 2, 4, ...)
- Odd numbers must go to odd indices (1, 3, 5, ...)

Key Idea:
Use two pointers to track next available positions:
- evenptr → next even index
- oddptr → next odd index

As we traverse the array, we place each number directly in its correct slot.

Approach:
1. Create result array of same size.
2. Initialize:
   - evenptr = 0
   - oddptr = 1
3. Traverse input array:
   - If number is even → place at evenptr, move evenptr + 2
   - Else → place at oddptr, move oddptr + 2
4. Return result array

Example:

Input:
nums = [4,2,5,7]

Step:
4 → even index 0
2 → even index 2
5 → odd index 1
7 → odd index 3

Output:
[4,5,2,7]

Why This Works:
Since half numbers are even and half are odd,
we can deterministically assign each to correct parity positions
without conflict.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern Used:
Two Pointer Placement / Index Bucketing

Key Learning:
When constraints guarantee distribution (even/odd split),
use direct indexing instead of sorting.
*/



class Solution {
public:

    vector<int> sortArrayByParityII(vector<int>& nums) {

        // Size of array
        int n = nums.size();

        // Result array
        vector<int> ans(n);

        // Pointer for even indices (0,2,4,...)
        int evenptr = 0;

        // Pointer for odd indices (1,3,5,...)
        int oddptr = 1;

        // Traverse input array
        for(int i = 0; i < n; i++)
        {
            // If number is even
            if(nums[i] % 2 == 0)
            {
                // Place at even index
                ans[evenptr] = nums[i];

                // Move to next even slot
                evenptr += 2;
            }
            else
            {
                // Place at odd index
                ans[oddptr] = nums[i];

                // Move to next odd slot
                oddptr += 2;
            }
        }

        return ans;
    }
};
