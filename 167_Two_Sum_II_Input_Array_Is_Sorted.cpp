/*
Problem 167. Two Sum II - Input Array Is Sorted

Problem Statement:

Given a 1-indexed array of integers numbers that is already sorted
in non-decreasing order, find two numbers such that they add up
to a specific target number.

Return the indices of the two numbers (1-indexed).

It is guaranteed that exactly one solution exists.

--------------------------------------------------

Intuition:

A brute force approach would check every pair of elements.

For each element:
    Compare it with every other element.

This would take O(n²) time.

However, the array is already sorted.

Since the array is sorted, we can use the Two Pointer technique.

--------------------------------------------------

Key Observation:

If the current sum is too large:

numbers[left] + numbers[right] > target

Since the array is sorted, decreasing the right pointer
will decrease the sum.

--------------------------------------------------

Similarly:

If the current sum is too small:

numbers[left] + numbers[right] < target

Increasing the left pointer will increase the sum.

--------------------------------------------------

Approach:

1. Place one pointer at the beginning.
2. Place another pointer at the end.
3. Calculate the current sum.
4. If the sum equals target:
      Return the indices.
5. If the sum is greater than target:
      Move right pointer left.
6. If the sum is less than target:
      Move left pointer right.
7. Continue until the answer is found.

--------------------------------------------------

Example:

numbers = [2,7,11,15]
target = 9

left = 0, right = 3

2 + 15 = 17 > 9
Move right pointer.

left = 0, right = 2

2 + 11 = 13 > 9
Move right pointer.

left = 0, right = 1

2 + 7 = 9

Answer = [1,2]

--------------------------------------------------

Why This Works:

The array is sorted.

When the sum is too large:
    The only way to reduce it is to move the right pointer left.

When the sum is too small:
    The only way to increase it is to move the left pointer right.

Thus, every move eliminates one impossible candidate pair,
allowing us to find the answer in linear time.

--------------------------------------------------

Time Complexity: O(n)

Each pointer moves at most n times.

--------------------------------------------------

Space Complexity: O(1)

Only a few variables are used.

--------------------------------------------------

Pattern Used:
Two Pointers

Key Learning:

1. Whenever an array is sorted, think about Two Pointers.
2. Two Pointers often reduces O(n²) brute force solutions to O(n).
3. One pointer controls smaller values while the other controls
   larger values.
4. This is one of the most important Two Pointer interview problems.
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Pointer starting from the beginning of the array
        int start = 0;

        // Pointer starting from the end of the array
        int end = numbers.size() - 1;

        // Continue until pointers meet
        while(start < end)
        {
            // Calculate the sum of the current pair
            int curr_sum = numbers[start] + numbers[end];

            // If target is found
            if(curr_sum == target)
            {
                // Return 1-based indices as required by the problem
                return {start + 1, end + 1};
            }

            // Current sum is too large
            // Move right pointer left to decrease the sum
            else if(curr_sum > target)
            {
                end--;
            }

            // Current sum is too small
            // Move left pointer right to increase the sum
            else
            {
                start++;
            }
        }

        // Safety return (problem guarantees a solution exists)
        return {};
    }
};
