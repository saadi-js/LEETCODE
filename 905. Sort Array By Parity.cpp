/*
Problem 905. Sort Array By Parity

Problem Statement:

Given an integer array nums, move all the even integers to the beginning
of the array, followed by all the odd integers.

Return the modified array.

The relative order among even or odd numbers does not matter.

--------------------------------------------------

Intuition:

We only need to partition the array into two groups:

- Even numbers
- Odd numbers

This is similar to partitioning in Quick Sort.

We maintain two pointers:

- i scans every element.
- j keeps track of the position where the next even number should be placed.

Whenever we encounter an even number, we swap it with the element at
index j and move both pointers forward.

Odd numbers are simply skipped.

--------------------------------------------------

Key Idea:

Step 1: Traverse the array using pointer i.
Step 2: Maintain pointer j for the next even position.
Step 3: If nums[i] is even:
        - Swap nums[i] with nums[j].
        - Increment both pointers.
Step 4: Otherwise, move only i.
Step 5: After one traversal, all even numbers appear before odd numbers.

--------------------------------------------------

Approach:

1. Initialize:
   - i = 0 (current element)
   - j = 0 (next position for an even number)
2. Traverse the array.
3. If nums[i] is even:
   - Swap nums[i] and nums[j].
   - Increment both i and j.
4. Otherwise:
   - Increment only i.
5. Return the modified array.

--------------------------------------------------

Example:

Input:

nums = [3,1,2,4]

Process:

i = 0

3 is odd

No swap

------------------

i = 1

1 is odd

No swap

------------------

i = 2

2 is even

Swap with index 0

[2,1,3,4]

j = 1

------------------

i = 3

4 is even

Swap with index 1

[2,4,3,1]

Finished.

Output:

[2,4,3,1]

--------------------------------------------------

Counter Example:

Input:

nums = [2,4,6]

Every element is already even.

Each swap occurs with the same position.

Output:

[2,4,6]

--------------------------------------------------

Why This Works:

Pointer j always marks the boundary between processed even numbers
and the remaining elements.

Whenever an even number is found, placing it at index j expands the
even partition.

After the traversal:

- All indices before j contain even numbers.
- All remaining indices contain odd numbers.

--------------------------------------------------

Time Complexity: O(n)

Each element is visited exactly once.

--------------------------------------------------

Space Complexity: O(1)

The array is rearranged in-place using only two pointers.

--------------------------------------------------

Pattern Used:
Two Pointers / Array Partitioning

Key Learning:

1. Partitioning is useful when dividing elements into two categories.
2. One pointer scans the array, while the other tracks the insertion position.
3. In-place partitioning avoids extra memory.
4. This technique is similar to the partition step of Quick Sort and appears frequently in array problems.
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int i = 0;
        int j = 0;

        while(i < nums.size())
        {
            if(nums[i] % 2 == 0)
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        return nums;
    }
};
