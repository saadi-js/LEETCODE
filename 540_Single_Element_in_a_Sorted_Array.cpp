/*
Problem 540. Single Element in a Sorted Array

Problem Statement:
You are given a sorted array consisting of only integers where every
element appears exactly twice, except for one element which appears
exactly once. Find this single element.

You must implement a solution with O(log n) time and O(1) space.

--------------------------------------------------

Intuition:

In a sorted array where every element appears twice, pairs sit at
indices (0,1), (2,3), (4,5)... i.e. even index followed by odd index.

Once the single element is passed, this pairing shifts:
pairs become (odd, even) instead of (even, odd).

We can use binary search on this pairing property.

--------------------------------------------------

Key Idea:

For any mid:
- Ensure mid is even (if odd, decrement by 1)
- If nums[mid] == nums[mid+1]: single element is to the RIGHT
  (pairing still intact on the left)
- Else: single element is at mid or to the LEFT
  (pairing has been disrupted)

--------------------------------------------------

Approach:

1. left=0, right=n-1
2. While left < right:
   - mid = left + (right-left)/2
   - If mid is odd: mid-- (force even)
   - If nums[mid] == nums[mid+1]: left = mid+2
   - Else: right = mid
3. Return nums[left]

--------------------------------------------------

Example:

nums = [1,1,2,3,3,4,4,8,8]

Indices: 0,1,2,3,4,5,6,7,8

mid=4 (even): nums[4]=3, nums[5]=4 → not equal → right=4
mid=2 (even): nums[2]=2, nums[3]=3 → not equal → right=2
mid=0 (even): nums[0]=1, nums[1]=1 → equal → left=2

left==right==2 → return nums[2] = 2

Output: 2

--------------------------------------------------

Why Force Even Mid?

The pairing structure only makes sense when mid is even.
If mid is odd, decrementing makes it the left element of the
current pair so the comparison nums[mid]==nums[mid+1] is valid.

--------------------------------------------------

Time Complexity: O(log n)

Binary search halves the search space each iteration.

--------------------------------------------------

Space Complexity: O(1)

Only pointer variables used.

--------------------------------------------------

Pattern Used:
Binary Search on Pairing Property

Key Learning:

1. Binary search works on any monotonic property, not just sorted values.
2. The even/odd index pairing property is the key insight here.
3. Forcing mid to be even simplifies the comparison logic.
4. When the pair matches (nums[mid]==nums[mid+1]), the single element
   must be further right — move left past both elements.
*/



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while(left < right)
        {
            int mid = left + (right - left) / 2;

            // Force mid to be even for consistent pair checking
            if(mid % 2 != 0)
            {
                mid--;
            }

            // If pair is intact, single element is to the right
            if(nums[mid] == nums[mid + 1])
            {
                left = mid + 2;
            }
            else
            {
                // Pairing disrupted — single element at mid or left
                right = mid;
            }
        }

        return nums[left];
    }
};
