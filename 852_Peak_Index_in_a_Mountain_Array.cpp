/*
Problem 852. Peak Index in a Mountain Array

Problem Statement:

An array arr is a mountain array if:

- It strictly increases to a peak element
- Then strictly decreases after the peak

You are given such an array and must return the index of the peak element.

--------------------------------------------------

Intuition:

A brute force solution would scan the array and find the maximum element.

That works in O(n) time.

But since the array has a special structure (mountain shape),
we can apply Binary Search.

--------------------------------------------------

Key Observation:

In a mountain array:

- If we are on the increasing slope → peak is to the right
- If we are on the decreasing slope → peak is to the left (or at mid)

So we can decide direction using:

arr[mid] vs arr[mid + 1]

--------------------------------------------------

Critical Insight:

If:

arr[mid] < arr[mid + 1]

→ we are in the ascending part
→ peak lies to the right

Else:

arr[mid] > arr[mid + 1]

→ we are in the descending part
→ peak lies at mid or to the left

--------------------------------------------------

Approach:

1. Initialize two pointers:
   - start = 0
   - end = n - 1

2. While start < end:
   - Compute mid
   - If arr[mid] < arr[mid + 1]:
        move start to mid + 1
   - Else:
        move end to mid

3. When loop ends, start == end → peak index

--------------------------------------------------

Example:

arr = [1,3,5,4,2]

Step 1:
mid = 2 (5)
5 > 4 → move left

Step 2:
search left half

Final peak = index 2

--------------------------------------------------

Why This Works:

A mountain array is strictly increasing then strictly decreasing,
so it guarantees exactly one peak.

Binary search works because:

- We always move toward the slope direction
- We eliminate half the search space each step

--------------------------------------------------

Time Complexity: O(log n)

Each step reduces the search space by half.

--------------------------------------------------

Space Complexity: O(1)

Only pointers are used.

--------------------------------------------------

Pattern Used:
Binary Search on Monotonic Structure

Key Learning:

1. Binary search is not only for sorted arrays.
2. It works on "monotonic behavior" (increasing/decreasing patterns).
3. Comparing mid with mid+1 helps determine slope direction.
4. This is a classic peak-finding pattern.
*/



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        // Start pointer of search space
        int start = 0;

        // End pointer of search space
        int end = arr.size() - 1;

        // Binary search loop
        while (start < end) {

            // Find middle index
            int mid = start + (end - start) / 2;

            // If we are on increasing slope
            // peak lies to the right
            if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;  // move right
            }

            // If we are on decreasing slope
            // peak lies at mid or to the left
            else {
                end = mid;        // move left (including mid)
            }
        }

        // start == end → peak index
        return start;
    }
};
