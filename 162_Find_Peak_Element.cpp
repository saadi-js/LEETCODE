/*
Problem 162. Find Peak Element

Problem Statement:
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element and return its index.

You may assume nums[-1] = nums[n] = -∞ (boundaries are negative infinity).
If multiple peaks exist, return the index of any one of them.

You must write an algorithm that runs in O(log n) time.

--------------------------------------------------

Intuition:

A linear scan finds a peak in O(n) easily.
But O(log n) requires binary search.

Key observation: if nums[mid] < nums[mid+1], the right side is
ascending — a peak must exist to the right (or at mid+1).
If nums[mid] > nums[mid+1], the left side has a descent — a peak
must exist to the left (or at mid).

--------------------------------------------------

Key Idea:

Binary search on the slope direction:

- If nums[mid] < nums[mid+1]: peak is to the RIGHT → left = mid+1
- If nums[mid] > nums[mid+1]: peak is at mid or LEFT → right = mid

When left == right, we have found a peak.

--------------------------------------------------

Approach:

1. left=0, right=n-1
2. While left < right:
   - mid = left + (right-left)/2
   - If nums[mid] > nums[mid+1]: right = mid
   - Else: left = mid+1
3. Return left

--------------------------------------------------

Example:

nums = [1,2,3,1]

left=0, right=3
mid=1: nums[1]=2 < nums[2]=3 → left=2
mid=2: nums[2]=3 > nums[3]=1 → right=2

left==right==2 → return 2

Output: 2 (nums[2]=3 is peak)

--------------------------------------------------

Why This Always Finds a Peak?

At every step we move toward a side that is guaranteed to contain
a peak. If we are on an ascending slope (nums[mid] < nums[mid+1]),
the element to the right is larger — either it is a peak or there
is a peak further right. We never eliminate the actual peak.

--------------------------------------------------

Time Complexity: O(log n)

Binary search halves the search space each step.

--------------------------------------------------

Space Complexity: O(1)

Only pointer variables used.

--------------------------------------------------

Pattern Used:
Binary Search on Monotonic Slope (Peak Finding)

Key Learning:

1. Binary search works whenever there is a monotonic decision rule
   — not just on sorted arrays.
2. Comparing nums[mid] with nums[mid+1] tells us which slope we
   are on and which direction contains a peak.
3. This same pattern is used in Peak Index in Mountain Array (852)
   which is a special case of this problem.
4. The invariant is: a peak always exists in [left, right].
*/



class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while(left < right)
        {
            int mid = left + (right - left) / 2;

            // On descending slope — peak is at mid or to the left
            if(nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                // On ascending slope — peak is to the right
                left = mid + 1;
            }
        }

        // left == right — peak index
        return left;
    }
};
