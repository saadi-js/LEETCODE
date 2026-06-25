/*
Problem 485. Max Consecutive Ones

Problem Statement:
Given a binary array nums, return the maximum number of consecutive
1s in the array.

--------------------------------------------------

Intuition:

We need to find the longest run of 1s in the array.

A single pass is sufficient — maintain a running count of
consecutive 1s and reset it whenever a 0 is encountered.

--------------------------------------------------

Key Idea:

Maintain two variables:
- count   → current streak of consecutive 1s
- maxlen  → longest streak seen so far

When nums[i] == 1 → increment count, update maxlen
When nums[i] == 0 → reset count to 0

--------------------------------------------------

Approach:

1. Initialize count = 0, maxlen = 0.
2. Traverse nums:
   - If nums[i] == 1: count++, maxlen = max(count, maxlen)
   - Else: count = 0
3. Return maxlen.

--------------------------------------------------

Example:

nums = [1,1,0,1,1,1]

i=0: 1 → count=1, maxlen=1
i=1: 1 → count=2, maxlen=2
i=2: 0 → count=0
i=3: 1 → count=1, maxlen=2
i=4: 1 → count=2, maxlen=2
i=5: 1 → count=3, maxlen=3

Output: 3

--------------------------------------------------

Why This Works:

Every time we see a 0 the current streak is broken so resetting
count is correct. Updating maxlen inside the if block ensures
we always track the peak streak seen so far.

--------------------------------------------------

Time Complexity: O(n)

Single pass through the array.

--------------------------------------------------

Space Complexity: O(1)

Only two integer variables used.

--------------------------------------------------

Pattern Used:
Array / Single Pass Streak Counting

Key Learning:

1. Streak-counting problems always follow the same pattern:
   increment on match, reset on mismatch, track global max.
2. This is the foundation for harder problems like Max Consecutive
   Ones III (with k flips allowed) which adds a sliding window.
3. Update maxlen inside the if block, not outside, to avoid
   counting streaks that ended on the previous element.
*/



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        // Tracks current streak of consecutive 1s
        int count = 0;

        // Tracks longest streak seen so far
        int maxlen = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                // Extend current streak
                count++;

                // Update maximum if current streak is longer
                maxlen = max(count, maxlen);
            }
            else
            {
                // Streak broken — reset counter
                count = 0;
            }
        }

        return maxlen;
    }
};
