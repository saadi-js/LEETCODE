/*
Problem 80. Remove Duplicates from Sorted Array II

Problem Statement:
Given a sorted integer array nums, remove duplicates in-place such that
each unique element appears at most twice. Return the number of elements
after removal.

The relative order of elements must be preserved.

--------------------------------------------------

Intuition:

This is an extension of Problem 26 (Remove Duplicates — allow once).

In Problem 26: keep element if nums[j] != nums[i-1]
In Problem 80: keep element if nums[j] != nums[i-2]

The key insight is that in a sorted array, if the current element
equals the element two positions back in the valid portion, we already
have two copies — skip it.

--------------------------------------------------

Key Idea:

Use a write pointer i starting at 2 (first two elements always kept).
Use a read pointer j starting at 2.

For each nums[j]:
- If nums[j] != nums[i-2]: keep it (write at i, advance i)
- Else: skip it (more than 2 copies)

--------------------------------------------------

Approach:

1. Handle edge case: if n <= 2, return n (already valid).
2. Initialize i = 2 (write pointer).
3. For j from 2 to n-1:
   - If nums[j] != nums[i-2]:
       nums[i] = nums[j]
       i++
4. Return i.

--------------------------------------------------

Example:

nums = [1,1,1,2,2,3]

i=2, j=2: nums[2]=1 == nums[0]=1 → skip
i=2, j=3: nums[3]=2 != nums[0]=1 → keep, nums[2]=2, i=3
i=3, j=4: nums[4]=2 != nums[1]=1 → keep, nums[3]=2, i=4
i=4, j=5: nums[5]=3 != nums[2]=2 → keep, nums[4]=3, i=5

Result: [1,1,2,2,3], length = 5

--------------------------------------------------

Why Comparing with nums[i-2]?

In a sorted array, if the current element equals the element
two positions back in the valid portion, it means we already
placed two copies of this value. A third copy must be skipped.

The comparison is against the write pointer position (i-2),
not the original array position.

--------------------------------------------------

Time Complexity: O(n)

Single pass through the array.

--------------------------------------------------

Space Complexity: O(1)

In-place modification.

--------------------------------------------------

Pattern Used:
Two Pointers (Write Pointer / Allow-K Duplicates)

Key Learning:

1. The "allow at most k duplicates" pattern generalizes:
   compare nums[j] with nums[i-k] — skip if equal.
2. For k=1 → Problem 26, for k=2 → Problem 80.
3. First k elements are always valid in a sorted array.
4. The write pointer i tracks the next valid write position.
*/



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        // Edge case: 2 or fewer elements are always valid
        if(n <= 2) return n;

        // Write pointer starts at 2 (first two elements always kept)
        int i = 2;

        // Read pointer scans from index 2 onward
        for(int j = 2; j < n; j++)
        {
            // Keep element only if it differs from element two positions back
            if(nums[j] != nums[i - 2])
            {
                nums[i] = nums[j];
                i++;
            }
            // Otherwise skip — would create a third duplicate
        }

        return i;
    }
};
