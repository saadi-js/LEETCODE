/*
Problem 26. Remove Duplicates from Sorted Array

Problem Statement:

Given an integer array nums sorted in non-decreasing order,
remove the duplicates in-place such that each unique element appears only once.

Return the number of unique elements.

You must do this by modifying the input array in-place
with O(1) extra memory.

--------------------------------------------------

Intuition:

Since the array is sorted, all duplicate elements appear consecutively.

Example:
nums = [1,1,2,2,3]

We only need to keep one occurrence of each number.

So whenever we see a new number different from the last unique one,
we place it in the next available position.

--------------------------------------------------

Key Idea:

Use two pointers:

1. slow pointer → tracks position of last unique element
2. fast pointer → scans the array

Whenever nums[fast] is different from nums[slow],
we move slow forward and overwrite nums[slow].

--------------------------------------------------

Approach:

1. If array is empty, return 0.
2. Initialize slow = 0.
3. Start fast from index 1.
4. Traverse the array:
   - If nums[fast] != nums[slow]:
       - Increment slow
       - Copy nums[fast] to nums[slow]
5. Return slow + 1 as count of unique elements.

--------------------------------------------------

Example Walkthrough:

nums = [1,1,2,2,3]

Initial:
slow = 0 → points to 1

fast = 1 → 1 == 1 → skip
fast = 2 → 2 != 1 → slow=1 → nums[1]=2
fast = 3 → 2 == 2 → skip
fast = 4 → 3 != 2 → slow=2 → nums[2]=3

Final array:
[1,2,3,...]

Return = 3

--------------------------------------------------

Why This Works:

Since the array is sorted:

- All duplicates are adjacent
- We only need to compare current element with last unique element
- No need for extra data structures like sets

--------------------------------------------------

Time Complexity: O(n)

We traverse the array once.

--------------------------------------------------

Space Complexity: O(1)

All operations are done in-place.

--------------------------------------------------

Pattern Used:
Two Pointers (Slow & Fast)

Key Learning:

1. Sorted arrays often allow in-place deduplication.
2. Slow pointer stores "compressed" valid portion.
3. Fast pointer scans full array.
4. Very common pattern in array manipulation problems.
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Edge case: empty array has no unique elements
        if (nums.size() == 0) return 0;

        // slow pointer tracks position of last unique element
        int slow = 0;

        // fast pointer scans through the array
        for (int fast = 1; fast < nums.size(); fast++)
        {
            // If we find a new unique element
            if (nums[slow] != nums[fast])
            {
                // Move slow pointer forward
                slow++;

                // Place the new unique element at slow position
                nums[slow] = nums[fast];
            }
        }

        // Number of unique elements is slow index + 1
        return slow + 1;
    }
};
