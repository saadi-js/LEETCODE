/*
Problem 704. Binary Search

Problem Statement:
Given a sorted array of integers nums and an integer target,
return the index of target if it exists, otherwise return -1.

Intuition:
Since the array is sorted, we can eliminate half of the search space at every step.

Instead of linear search O(n), we use binary search O(log n).

Key Idea:
At each step:
- Compare target with middle element
- Decide whether to search left half or right half

This works because the array is sorted.

Approach:
1. Initialize two pointers:
   - left = 0
   - right = n - 1
2. While left <= right:
   a. Compute mid safely
   b. If nums[mid] == target → return mid
   c. If nums[mid] < target → search right half
   d. Else → search left half
3. If not found → return -1

Example:
nums = [-1,0,3,5,9,12], target = 9

Steps:
mid checks reduce search space:
→ 3 → 5 → 9 found

Why This Works:
Sorted order guarantees that one half of the array can be safely discarded at each step.

Time Complexity: O(log n)
Space Complexity: O(1)

Pattern Used:
Binary Search (Divide & Conquer on Sorted Array)

Key Learning:
Whenever data is sorted:
→ Think binary search immediately
*/



class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Left boundary of search space
        int left = 0;

        // Right boundary of search space
        int right = nums.size() - 1;

        // Continue while search space exists
        while(left <= right)
        {
            // Safe mid calculation to avoid overflow
            int mid = left + (right - left) / 2;

            // If target found, return index
            if(nums[mid] == target)
            {
                return mid;
            }

            // If middle value is smaller, search right half
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }

            // Otherwise search left half
            else
            {
                right = mid - 1;
            }
        }

        // Target not found
        return -1;
    }
};
