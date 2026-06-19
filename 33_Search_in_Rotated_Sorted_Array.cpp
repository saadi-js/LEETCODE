/*
Problem 33. Search in Rotated Sorted Array

Problem Statement:
Given a rotated sorted array with distinct elements, return the index of a target value.
If it does not exist, return -1.

A rotated array is a sorted array rotated at an unknown pivot.

Example:
Original: [1,2,3,4,5,6]
Rotated:  [4,5,6,1,2,3]

Intuition:
Even though the array is rotated, at least one half of the array is always sorted.

Key Idea:
At each step:
1. Identify which half is sorted (left or right)
2. Check if target lies in the sorted half
3. Eliminate the half that cannot contain target

This preserves binary search’s O(log n) behavior.

Approach:
1. Initialize start = 0, end = n-1
2. While start <= end:
   a. Compute mid
   b. If nums[mid] == target → return mid

3. Check which half is sorted:
   - Left half sorted if nums[start] <= nums[mid]
   - Otherwise right half is sorted

4. If left half is sorted:
   - If target lies within [nums[start], nums[mid]):
        search left half
     else:
        search right half

5. If right half is sorted:
   - If target lies within (nums[mid], nums[end]]:
        search right half
     else:
        search left half

Why This Works:
A rotated sorted array always has one monotonic half.
Binary search works by eliminating the irrelevant half each iteration.

Time Complexity: O(log n)
Space Complexity: O(1)

Pattern Used:
Binary Search on Rotated Sorted Array

Key Learning:
When array is rotated:
→ Always identify sorted half before deciding direction
*/



class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Search boundaries
        int start = 0;
        int end = nums.size() - 1;

        // Standard binary search loop
        while(start <= end)
        {
            // Mid index
            int mid = start + (end - start) / 2;

            // Target found
            if(nums[mid] == target)
            {
                return mid;
            }

            // Check if LEFT half is sorted
            if(nums[start] <= nums[mid])
            {
                // Target lies in left sorted half
                if(nums[start] <= target && target < nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            // Otherwise RIGHT half is sorted
            else
            {
                // Target lies in right sorted half
                if(nums[mid] < target && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }

        // Target not found
        return -1;
    }
};
