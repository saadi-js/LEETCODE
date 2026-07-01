/*
Problem 209. Minimum Size Subarray Sum

Problem Statement:
Given an array of positive integers nums and a positive integer target,
return the minimal length of a subarray whose sum is greater than or
equal to target. If no such subarray exists, return 0.

--------------------------------------------------

Intuition:

A brute force approach checks every subarray — O(n²).

Since all elements are positive, the sum of a window is monotonically
increasing as we expand right and decreasing as we shrink left.

This monotonic property makes it a perfect sliding window problem.

--------------------------------------------------

Key Idea:

Use a variable-size sliding window:
- Expand right pointer and add to sum
- When sum >= target, try to shrink from left to find minimum length
- Keep shrinking as long as sum remains >= target

--------------------------------------------------

Approach:

1. Initialize left = 0, sum = 0, minlen = INT_MAX.
2. Expand right pointer:
   - Add nums[right] to sum
   - While sum >= target:
       Update minlen = min(minlen, right - left + 1)
       Subtract nums[left] from sum
       Move left++
3. Return minlen == INT_MAX ? 0 : minlen

--------------------------------------------------

Example:

nums = [2,3,1,2,4,3], target = 7

right=0: sum=2
right=1: sum=5
right=2: sum=6
right=3: sum=8 >= 7 → minlen=4, shrink: sum=6, left=1
right=4: sum=10 >= 7 → minlen=3, shrink: sum=7 >= 7 → minlen=2, shrink: sum=4, left=3
right=5: sum=7 >= 7 → minlen=2, shrink: sum=5, left=4

Output: 2

--------------------------------------------------

Why This Works:

All values are positive so adding elements always increases sum and
removing always decreases it. This guarantees the window is valid to
shrink as long as sum >= target without missing any candidates.

--------------------------------------------------

Time Complexity: O(n)

Each element is added and removed from the window at most once.

--------------------------------------------------

Space Complexity: O(1)

Only pointer and sum variables used.

--------------------------------------------------

Pattern Used:
Variable Size Sliding Window (Shrink when condition satisfied)

Key Learning:

1. When all elements are positive, sliding window works perfectly
   for minimum/maximum subarray problems.
2. Shrink the window WHILE the condition holds (not just once) to
   find the true minimum length.
3. Initialize minlen to INT_MAX and return 0 if never updated —
   handles the case where no valid subarray exists.
*/



class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // Left boundary of window
        int left = 0;

        // Minimum length found so far
        int minlen = INT_MAX;

        // Current window sum
        int sum = 0;

        // Expand window with right pointer
        for(int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];

            // Shrink window while sum meets target
            while(sum >= target)
            {
                // Update minimum length
                minlen = min(minlen, right - left + 1);

                // Remove left element and shrink
                sum -= nums[left];
                left++;
            }
        }

        // Return 0 if no valid subarray found
        return (minlen == INT_MAX) ? 0 : minlen;
    }
};
