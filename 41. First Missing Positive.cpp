/*
Problem 41. First Missing Positive

Problem Statement:

Given an unsorted integer array nums, return the smallest missing
positive integer.

You must solve the problem in O(n) time and use O(1) extra space.

--------------------------------------------------

Intuition:

The smallest missing positive number must lie in the range:

1 to n + 1

where n is the size of the array.

Reason:

- If every number from 1 to n exists, then the answer is n + 1.
- Otherwise, the missing number is somewhere between 1 and n.

Instead of using extra space like a HashSet, we can use the array itself
to place every positive number x at its correct index:

x should be stored at index (x - 1).

After every valid number is placed correctly, the first position where
nums[i] != i + 1 reveals the smallest missing positive.

--------------------------------------------------

Key Idea:

Step 1: Traverse the array.
Step 2: While a number is valid (1 ≤ x ≤ n) and not already in its
        correct position, swap it into its correct index.
Step 3: After all numbers are placed, scan the array.
Step 4: The first index where nums[i] != i + 1 gives the answer.
Step 5: If every position is correct, return n + 1.

--------------------------------------------------

Approach:

1. Let n be the size of the array.
2. Traverse every index i.
3. While:
   - nums[i] is positive.
   - nums[i] ≤ n.
   - nums[i] is not already at its correct position.
   swap nums[i] with nums[nums[i] - 1].
4. Traverse the array again.
5. The first index where nums[i] != i + 1 is the missing positive.
6. If every position is correct, return n + 1.

--------------------------------------------------

Example:

Input:

nums = [3,4,-1,1]

Initial:

[3,4,-1,1]

Swap 3 with position 2

[-1,4,3,1]

Swap 4 with position 3

[-1,1,3,4]

Swap 1 with position 0

[1,-1,3,4]

Scan the array:

Index 0 → 1 ✔

Index 1 → Expected 2, found -1 ✘

Smallest missing positive = 2

Output:
2

--------------------------------------------------

Counter Example:

Input:

nums = [1,2,0]

After placement:

[1,2,0]

Scan:

Index 0 → 1 ✔

Index 1 → 2 ✔

Index 2 → Expected 3, found 0 ✘

Output:
3

--------------------------------------------------

Why This Works:

Each valid number is moved to its correct position in the array.

After the placement phase:

- Index 0 should contain 1.
- Index 1 should contain 2.
- Index 2 should contain 3.
- ...

If a position does not contain its expected value, then that expected
value is the smallest missing positive integer.

Since every swap places at least one number into its correct position,
the total number of swaps is linear.

--------------------------------------------------

Time Complexity: O(n)

Although the algorithm contains a while loop, each element is moved
to its correct position at most once, resulting in an overall O(n)
time complexity.

--------------------------------------------------

Space Complexity: O(1)

The array itself is used for rearrangement, and only a few variables
are required.

--------------------------------------------------

Pattern Used:
Cyclic Sort / Index Placement

Key Learning:

1. When numbers belong to a fixed range (1 to n), the array itself can
   be used as a hash table.
2. Place each value x at index x - 1 whenever possible.
3. A nested while loop does not necessarily imply O(n²); here, each
   element is swapped at most once, giving O(n) time.
4. Cyclic Sort is a powerful pattern for problems involving missing,
   duplicate, or misplaced numbers.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        // Place every valid number at its correct position
        for(int i = 0; i < n; i++)
        {
            while(nums[i] > 0 &&
                  nums[i] <= n &&
                  nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first missing positive
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};
