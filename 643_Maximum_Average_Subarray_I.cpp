/*
Problem 643. Maximum Average Subarray I

Problem Statement:
Given an integer array nums consisting of n elements and an integer k,
find a contiguous subarray whose length is exactly k and has the maximum
average value. Return this maximum average.

Intuition:
Since every valid subarray must have a fixed size k, calculating the sum
from scratch for every possible subarray would be inefficient.

Instead, we can calculate the sum of the first window of size k and then
slide the window one position at a time.

As the window moves:
- Add the new element entering the window.
- Remove the element leaving the window.

This allows us to maintain the current window sum in O(1) time per shift.

Key Idea:
Use a Fixed Size Sliding Window.

Maintain:
- sumk = current window sum
- maxsum = maximum window sum found so far

Since the window size is constant, the subarray with the largest sum will
also have the largest average.

Approach:
1. Calculate the sum of the first k elements.
2. Store it as the current maximum sum.
3. Slide the window from index k to the end.
4. Add the incoming element.
5. Remove the outgoing element.
6. Update the maximum sum.
7. Return maxsum divided by k as a double.

Example:
nums = [1,12,-5,-6,50,3]
k = 4

First window:
[1,12,-5,-6]
Sum = 2

Slide:

[12,-5,-6,50]
Sum = 51

[-5,-6,50,3]
Sum = 42

Maximum Sum = 51

Maximum Average = 51 / 4 = 12.75

Why This Works:
Every valid subarray has the same length k.

Since:
Average = Sum / k

and k remains constant, maximizing the sum automatically maximizes
the average.

The sliding window ensures each element is processed only once.

Time Complexity: O(n)

Space Complexity: O(1)

Pattern Used:
Sliding Window (Fixed Size)

Key Learning:
For fixed-size subarray problems involving maximum/minimum sums,
averages, counts, or frequencies, use a Fixed Size Sliding Window
to avoid recomputing values repeatedly.
*/



class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        // Size of the array
        int n = nums.size();

        // Stores the sum of the current window of size k
        int sumk;

        // Calculate the sum of the first window
        for(int i = 0; i < k; i++)
        {
            sumk += nums[i];
        }

        // Initialize maximum sum using the first window
        int maxsum = sumk;

        // Slide the window across the array
        for(int i = k; i < n; i++)
        {
            // Add the new element entering the window
            sumk += nums[i];

            // Remove the element leaving the window
            sumk -= nums[i-k];

            // Update the maximum window sum found so far
            maxsum = max(sumk, maxsum);
        }

        // Convert to double before division to preserve decimal values
        return (double)maxsum / k;
    }
};
