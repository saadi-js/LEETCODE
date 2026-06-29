/*
Problem 228. Summary Ranges

Problem Statement:

Given a sorted unique integer array nums, return the smallest sorted
list of ranges that cover all the numbers in the array exactly.

Each range should be formatted as:

- "a"      if the range contains only one number.
- "a->b"   if the range contains multiple consecutive numbers.

--------------------------------------------------

Intuition:

Since the array is already sorted and contains unique elements,
consecutive numbers appear next to each other.

We can treat every consecutive sequence as one range:

- Mark the beginning of the range.
- Continue moving until the sequence breaks.
- Record the range.
- Start again from the next number.

--------------------------------------------------

Key Idea:

Step 1: Use a pointer `left` to mark the beginning of a range.
Step 2: Expand another pointer `right` while numbers remain consecutive.
Step 3: If both pointers are equal, the range contains one element.
Step 4: Otherwise, store the range as "left->right".
Step 5: Repeat until the entire array is processed.

--------------------------------------------------

Approach:

1. Initialize `left = 0`.
2. While `left` is within the array:
   - Set `right = left`.
   - Move `right` forward while consecutive numbers exist.
3. If `left == right`:
   - Store the single number.
4. Otherwise:
   - Store "nums[left]->nums[right]".
5. Move `left` to `right + 1`.
6. Return the list of ranges.

--------------------------------------------------

Example:

Input:

nums = [0,1,2,4,5,7]

Process:

Range 1:

0 → 1 → 2

Store:

"0->2"

------------------

Range 2:

4 → 5

Store:

"4->5"

------------------

Range 3:

7

Store:

"7"

Output:

["0->2","4->5","7"]

--------------------------------------------------

Counter Example:

Input:

nums = [5]

Only one number exists.

Store:

"5"

Output:

["5"]

--------------------------------------------------

Why This Works:

The `right` pointer always expands as long as the numbers remain
consecutive.

When the sequence breaks, we have identified one complete range.

Moving `left` to `right + 1` ensures every number is processed exactly
once without overlap.

--------------------------------------------------

Time Complexity: O(n)

Each element is visited at most once by the two pointers.

--------------------------------------------------

Space Complexity: O(1)

Ignoring the output array, only a few variables are used.

(The output vector is not counted toward auxiliary space.)

--------------------------------------------------

Pattern Used:
Two Pointers / Interval Construction

Key Learning:

1. Consecutive sequences can often be represented as intervals.
2. Two pointers are useful when expanding a valid range.
3. Since each pointer only moves forward, the algorithm runs in linear time.
4. `to_string()` is convenient for converting integers into formatted string ranges.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        int left = 0;
        int n = nums.size();

        vector<string> ans;

        while(left < n)
        {
            int right = left;

            // Expand the current consecutive range
            while(right + 1 < n &&
                  nums[right + 1] == nums[right] + 1)
            {
                right++;
            }

            // Single element range
            if(left == right)
            {
                ans.push_back(to_string(nums[left]));
            }
            else
            {
                // Multiple element range
                ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
            }

            // Start the next range
            left = right + 1;
        }

        return ans;
    }
};
