/*
Problem 75. Sort Colors

Problem Statement:

Given an array nums containing n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent, with
the colors in the order:

Red (0), White (1), Blue (2)

You must solve this problem without using the library's sort function.

--------------------------------------------------

Intuition:

Since the array contains only three distinct values (0, 1, and 2),
we do not need a general-purpose sorting algorithm.

Instead, we can partition the array into three regions while traversing
it only once:

- Left region contains all 0's.
- Middle region contains all 1's.
- Right region contains all 2's.

This is known as the Dutch National Flag Algorithm.

--------------------------------------------------

Key Idea:

Maintain three pointers:

- low  → Next position where a 0 should be placed.
- mid  → Current element being processed.
- high → Next position where a 2 should be placed.

Rules:

1. If nums[mid] == 0:
   - Swap nums[low] and nums[mid].
   - Increment both low and mid.

2. If nums[mid] == 1:
   - It is already in the correct region.
   - Increment mid.

3. If nums[mid] == 2:
   - Swap nums[mid] and nums[high].
   - Decrement high.
   - Do NOT increment mid because the swapped element has not been processed yet.

--------------------------------------------------

Approach:

1. Initialize:
   - low = 0
   - mid = 0
   - high = n - 1
2. Traverse while mid <= high.
3. Depending on nums[mid]:
   - If 0:
     - Swap with nums[low].
     - Increment low and mid.
   - If 1:
     - Increment mid.
   - If 2:
     - Swap with nums[high].
     - Decrement high.
4. Continue until all elements are processed.

--------------------------------------------------

Example:

Input:

nums = [2,0,2,1,1,0]

Initial:

low = 0
mid = 0
high = 5

Step 1:

2 found
Swap with high

[0,0,2,1,1,2]

high--

Step 2:

0 found
Swap with low

[0,0,2,1,1,2]

low++
mid++

Step 3:

0 found

low++
mid++

Step 4:

2 found

Swap with high

[0,0,1,1,2,2]

high--

Step 5:

1 found

mid++

Step 6:

1 found

mid++

Finished.

Output:

[0,0,1,1,2,2]

--------------------------------------------------

Counter Example:

Input:

nums = [2,1]

Process:

Swap 2 with high

[1,2]

The swapped value (1) has not been processed yet,
so mid must NOT be incremented.

If we incremented mid immediately after swapping,
the new value at mid would never be examined.

Output:

[1,2]

--------------------------------------------------

Why This Works:

At every iteration:

- Everything before low is guaranteed to be 0.
- Everything after high is guaranteed to be 2.
- Everything between low and mid - 1 is guaranteed to be 1.
- The region from mid to high is still unprocessed.

Each operation expands one of the correctly sorted regions until
the entire array is partitioned correctly.

--------------------------------------------------

Time Complexity: O(n)

Each element is processed at most once.

--------------------------------------------------

Space Complexity: O(1)

Sorting is performed in-place using only three pointers.

--------------------------------------------------

Pattern Used:
Three Pointers / Dutch National Flag Algorithm

Key Learning:

1. When an array contains only a few distinct values, partitioning is often more efficient than sorting.
2. The Dutch National Flag Algorithm sorts three categories in a single traversal.
3. After swapping with the high pointer, do not increment mid because the incoming element is still unprocessed.
4. Clearly defining the invariant of each region helps in understanding and implementing pointer-based algorithms.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
    }
};
