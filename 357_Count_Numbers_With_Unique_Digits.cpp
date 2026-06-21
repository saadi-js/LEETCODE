/*
Problem 357. Count Numbers with Unique Digits

Problem Statement:
Given an integer n, return the count of all numbers with unique digits
for every number in the range [0, 10^n).

A number is considered valid if all its digits are unique.

Intuition:
We are counting how many numbers can be formed with unique digits
for different lengths (1-digit, 2-digit, ..., n-digit).

Instead of generating numbers, we use combinatorics:
- First digit has 9 choices (1-9)
- Next digit has 9 choices (0-9 excluding used digits)
- Then choices decrease progressively

Key Idea:
We compute:
- 1-digit numbers → 10 (0–9)
- 2-digit numbers → 9 × 9
- 3-digit numbers → 9 × 9 × 8
- 4-digit numbers → 9 × 9 × 8 × 7 ...

Then accumulate results.

Approach:
1. Handle base case: n == 0 → return 1
2. Initialize:
   - ans = 10 (for 0-digit and 1-digit numbers)
   - first = 9 (choices for first digit)
   - available = 9 (remaining digits)
3. Loop from i = 2 to n:
   - first *= available
   - add to ans
   - decrease available
4. Return ans

Example:

n = 2
1-digit: 10
2-digit:
  9 × 9 = 81

Total = 91

Why This Works:
We systematically count valid permutations without repetition,
reducing problem to combinatorics instead of brute force enumeration.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Combinatorics / Permutation counting

Key Learning:
When constraints involve “unique digits” or permutations,
use factorial-like decreasing choices instead of simulation.
*/



class Solution {
public:

    int countNumbersWithUniqueDigits(int n) {

        // Base case: only "0"
        if(n == 0) return 1;

        // Start with all 1-digit numbers (0–9)
        int ans = 10;

        // Choices for first digit (1–9)
        int first = 9;

        // Available digits for next positions
        int available = 9;

        // Build numbers of length 2 to n
        for(int i = 2; i <= n && available; i++)
        {
            // Multiply current choices
            first *= available;

            // Add to total answer
            ans += first;

            // Reduce available digits
            available--;
        }

        return ans;
    }
};
