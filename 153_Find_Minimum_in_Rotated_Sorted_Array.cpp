/*
Problem 153. Find Minimum in Rotated Sorted Array

Problem Statement:
Given a rotated sorted array with distinct elements, find the minimum element.

A rotated array is formed by taking a sorted array and rotating it at some pivot.

Example:
Original: [1,2,3,4,5]
Rotated:  [3,4,5,1,2]

Goal: return 1

Intuition:
We use binary search on the “pivot point”.

The minimum element is the only place where order breaks.

Key Idea:
Compare middle element with right boundary:

- If nums[mid] > nums[end]
  → minimum is in right half (mid+1 to end)

- Else
  → minimum is in left half (including mid)

We shrink search space until start == end.

Approach:
1. Initialize start = 0, end = n-1
2. While start < end:
   a. Compute mid
   b. If nums[mid] > nums[end]:
        → minimum is in right half
        → start = mid + 1
   c. Else:
        → minimum is in left half (including mid)
        → end = mid
3. Return nums[start]

Why This Works:
The rotated array maintains two sorted segments.
Comparing mid with end tells which segment we are in.

Time Complexity: O(log n)
Space Complexity: O(1)

Pattern Used:
Binary Search on Rotated Sorted Array

Key Learning:
When sorted array is rotated:
→ compare mid with boundary to decide direction
*/



class Solution {
public:
    int findMin(vector<int>& nums) {

        // Search boundaries
        int start = 0;
        int end = nums.size() - 1;

        // Narrow down until single element remains
        while(start < end)
        {
            // Safe mid calculation
            int mid = start + (end - start) / 2;

            // If mid element is greater than end,
            // minimum lies in right half
            if(nums[mid] > nums[end])
            {
                start = mid + 1;
            }
            else
            {
                // Minimum lies in left half including mid
                end = mid;
            }
        }

        // Start == end → minimum element
        return nums[start];
    }
};
