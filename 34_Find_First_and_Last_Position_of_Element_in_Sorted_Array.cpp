/*
Problem 34. Find First and Last Position of Element in Sorted Array

Problem Statement:
Given an array of integers nums sorted in non-decreasing order, find the
starting and ending position of a given target value.

If target is not found, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

--------------------------------------------------

Intuition:

Since the array is sorted, binary search can find the target.
But standard binary search stops at any occurrence.

We need the FIRST and LAST occurrence separately.

Key insight:
- For first occurrence: when found, store index and search LEFT
- For last occurrence: when found, store index and search RIGHT

--------------------------------------------------

Key Idea:

Two binary searches:

findFirst: standard BS but on match → store ans, move right = mid-1
findLast:  standard BS but on match → store ans, move left = mid+1

Both run independently in O(log n) each → O(log n) total.

--------------------------------------------------

Approach:

findFirst(nums, target):
1. left=0, right=n-1, ans=-1
2. While left <= right:
   - If nums[mid] == target: ans=mid, right=mid-1 (search left)
   - If nums[mid] < target: left=mid+1
   - Else: right=mid-1
3. Return ans

findLast(nums, target):
1. left=0, right=n-1, ans=-1
2. While left <= right:
   - If nums[mid] == target: ans=mid, left=mid+1 (search right)
   - If nums[mid] < target: left=mid+1
   - Else: right=mid-1
3. Return ans

--------------------------------------------------

Example:

nums = [5,7,7,8,8,10], target = 8

findFirst:
mid=2 (7) → left=3
mid=4 (8) → ans=4, right=3
mid=3 (8) → ans=3, right=2
→ returns 3

findLast:
mid=2 (7) → left=3
mid=4 (8) → ans=4, left=5
mid=5 (10) → right=4
→ returns 4

Output: [3, 4]

--------------------------------------------------

Why This Works:

When we find the target in findFirst, we save it as a candidate
and continue searching left — there might be an earlier occurrence.
The last saved candidate is the leftmost occurrence.

Symmetric logic applies for findLast searching right.

--------------------------------------------------

Time Complexity: O(log n)

Two independent binary searches, each O(log n).

--------------------------------------------------

Space Complexity: O(1)

Only pointer variables used.

--------------------------------------------------

Pattern Used:
Binary Search (First / Last Occurrence — Left/Right Boundary Search)

Key Learning:

1. To find first occurrence: on match, save and search LEFT.
2. To find last occurrence: on match, save and search RIGHT.
3. These are called left boundary and right boundary binary search.
4. This pattern is fundamental and appears in many BS variations
   like lower_bound and upper_bound in C++ STL.
*/



class Solution {
public:

    // Find first occurrence of target
    int findFirst(vector<int>& nums, int target)
    {
        int left = 0;
        int ans = -1;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target)
            {
                // Save and continue searching left
                ans = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }

    // Find last occurrence of target
    int findLast(vector<int>& nums, int target)
    {
        int left = 0;
        int ans = -1;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target)
            {
                // Save and continue searching right
                ans = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        return {findFirst(nums, target), findLast(nums, target)};
    }
};
