/*
Problem 35. Search Insert Position

Problem Statement:

Given a sorted array of distinct integers and a target value,
return the index if the target is found.

If the target is not found, return the index where it would be
inserted in order.

You must write an algorithm with O(log n) runtime complexity.

--------------------------------------------------

Intuition:

Since the array is sorted and the required complexity is O(log n),
Binary Search is the natural choice.

Normally in Binary Search:
- If target is found → return its index.

But here, if the target is not found,
we need to determine where it should be inserted.

--------------------------------------------------

Key Idea:

At the end of Binary Search:

- start points to the first position where target can be inserted.
- end points to the last element smaller than target.

Therefore, when the loop ends,
start is exactly the insertion position.

--------------------------------------------------

Approach:

1. Initialize:
   - start = 0
   - end = n - 1

2. Perform Binary Search:
   - If nums[mid] == target → return mid
   - If nums[mid] > target → search left half
   - Else → search right half

3. If target is not found:
   - return start

--------------------------------------------------

Example 1:

nums = [1,3,5,6]
target = 5

mid = 1 → 3
mid = 2 → 5 found

Answer = 2

--------------------------------------------------

Example 2:

nums = [1,3,5,6]
target = 2

Binary search ends with:

start = 1
end = 0

Answer = 1

Insert at index 1:
[1,2,3,5,6]

--------------------------------------------------

Example 3:

nums = [1,3,5,6]
target = 7

Binary search ends with:

start = 4

Answer = 4

Insert at end.

--------------------------------------------------

Why This Works:

Binary Search continuously narrows the search range.

When target doesn't exist:

- All elements before start are smaller than target.
- All elements after start are greater than target.

Thus start becomes the correct insertion position.

--------------------------------------------------

Time Complexity: O(log n)

Binary Search halves the search space every iteration.

--------------------------------------------------

Space Complexity: O(1)

No extra space used.

--------------------------------------------------

Pattern Used:
Binary Search

Key Learning:

1. Binary Search can find insertion positions, not just exact values.
2. When target is absent:
   - start becomes insertion index.
3. Very common lower-bound style problem.
*/



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // Start of search range
        int start = 0;

        // End of search range
        int end = nums.size() - 1;

        // Perform Binary Search
        while(start <= end)
        {
            // Compute middle index safely
            int mid = start + (end - start) / 2;

            // Target found
            if(nums[mid] == target)
            {
                return mid;
            }

            // Search left half
            else if(nums[mid] > target)
            {
                end = mid - 1;
            }

            // Search right half
            else
            {
                start = mid + 1;
            }
        }

        // Target not found
        // start points to insertion position
        return start;
    }
};
