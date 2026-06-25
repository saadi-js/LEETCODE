/*
Problem 268. Missing Number

Problem Statement:
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

--------------------------------------------------

Intuition:

A HashSet approach would store all elements and then check which
number from 0 to n is absent. That takes O(n) space.

We can do better using a mathematical observation:

The sum of numbers from 0 to n is always n*(n+1)/2.
If we subtract the actual sum of the array from this expected sum,
the difference is exactly the missing number.

--------------------------------------------------

Key Idea:

Expected sum of [0, n]  = n * (n + 1) / 2
Actual sum of array     = sum of all elements in nums
Missing number          = Expected sum - Actual sum

--------------------------------------------------

Approach:

1. Compute expected sum using the formula n*(n+1)/2.
2. Compute actual sum by iterating through nums.
3. Return expected - actual.

--------------------------------------------------

Example:

nums = [3, 0, 1]
n = 3

Expected sum = 3 * 4 / 2 = 6
Actual sum   = 3 + 0 + 1 = 4

Missing = 6 - 4 = 2

Output: 2

--------------------------------------------------

Alternative Approach (XOR):

XOR all indices 0 to n with all elements.
Duplicate values cancel out, leaving the missing number.

int x = 0;
for(int i = 0; i <= n; i++) x ^= i;
for(int num : nums) x ^= num;
return x;

Both approaches are O(n) time and O(1) space.

--------------------------------------------------

Why This Works:

The Gauss formula gives the exact sum a complete range should have.
Since all other numbers are present exactly once, the deficit
between expected and actual is precisely the missing number.

--------------------------------------------------

Time Complexity: O(n)

One pass to compute the actual sum.

--------------------------------------------------

Space Complexity: O(1)

Only two integer variables used.

--------------------------------------------------

Pattern Used:
Math / Gauss Formula (Sum of Range)

Key Learning:

1. When finding a missing element in a range, Gauss formula
   gives an O(1) space solution.
2. XOR approach is equally valid and O(1) space.
3. Both are better than sorting (O(n log n)) or HashSet (O(n) space).
4. This pattern extends to finding missing numbers in other ranges
   by adjusting the expected sum formula.
*/



class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // Size of array = n (range is [0, n])
        int n = nums.size();

        // Expected sum of complete range [0, n]
        int expectedSum = n * (n + 1) / 2;

        // Actual sum of elements present in array
        int sum = 0;

        for(int x : nums)
        {
            sum += x;
        }

        // Missing number is the difference
        return expectedSum - sum;
    }
};
