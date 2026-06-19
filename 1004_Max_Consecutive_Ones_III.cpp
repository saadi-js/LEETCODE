/*
Problem 1004. Max Consecutive Ones III

Problem Statement:
Given a binary array nums and an integer k, return the maximum number of consecutive 1s in the array
if you can flip at most k 0s.

Intuition:
We want the longest contiguous subarray that contains at most k zeros.

Instead of trying every possible subarray, we maintain a sliding window and track how many zeros
are currently inside the window.

If zeros exceed k, we shrink the window from the left until the constraint is satisfied again.

Key Idea:
Use Variable Size Sliding Window with a counter for zeros.

Maintain:
- [left, right] window
- zeros = number of 0s in current window
- ensure zeros ≤ k

Approach:
1. Expand the window using right pointer.
2. If nums[right] == 0, increment zeros count.
3. If zeros > k, shrink window from left:
   - If nums[left] == 0, decrement zeros
   - Move left forward
4. After each valid window, update maximum length.
5. Return maximum length found.

Example:
nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2

We maintain a window that allows at most 2 zeros.

Valid best window might include:
[1,1,1,0,0,1,1,1,1,1] → length = 10

Why This Works:
We only shrink when constraint is violated, ensuring every valid window is
maximized for the current right pointer.

Each element enters and exits the window at most once → linear time.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Variable Size Sliding Window (At Most K Invalid Elements)

Key Learning:
Whenever a problem says:
→ "flip k elements"
→ "at most k changes allowed"
→ "maximize consecutive segment"

Think:
Sliding Window + Counter (instead of full recomputation)
*/



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        // Left pointer of sliding window
        int left = 0;

        // Stores maximum length of valid window
        int maxlen = 0;

        // Count of zeros in current window
        int zeros = 0;

        // Expand window using right pointer
        for(int right = 0; right < nums.size(); right++)
        {
            // If current element is 0, increase zero count
            if(nums[right] == 0)
            {
                zeros++;
            }

            // If zeros exceed allowed flips, shrink window
            while(zeros > k)
            {
                // If left element is 0, reduce zero count
                if(nums[left] == 0)
                {
                    zeros--;
                }

                // Move left pointer forward
                left++;
            }

            // Update maximum window length
            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};
