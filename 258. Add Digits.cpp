/*
Problem 258. Add Digits

Problem Statement:

Given an integer num, repeatedly add all of its digits until the result
has only one digit, and return that single-digit result.

--------------------------------------------------

Intuition:

The number may contain multiple digits, so we first need a way to compute
the sum of its digits.

If the resulting sum is still a multi-digit number, we repeat the same
process until only a single digit remains.

This directly follows the problem statement and can be implemented using
a helper function.

--------------------------------------------------

Key Idea:

Step 1: Create a helper function to calculate the sum of digits of a number.
Step 2: While the number has more than one digit (num > 9),
        replace it with its digit sum.
Step 3: Once the number becomes a single digit, return it.

--------------------------------------------------

Approach:

1. Create a helper function `getsum()`:
   - Extract the last digit using `% 10`.
   - Add it to the running sum.
   - Remove the last digit using `/= 10`.
   - Continue until the number becomes 0.
2. In `addDigits()`, keep calculating the digit sum while the number
   contains more than one digit.
3. Return the final single-digit number.

--------------------------------------------------

Example:

Input:
num = 38

First iteration:
3 + 8 = 11

Second iteration:
1 + 1 = 2

Output:
2

--------------------------------------------------

Counter Example:

Input:
num = 999

First iteration:
9 + 9 + 9 = 27

Second iteration:
2 + 7 = 9

Output:
9

--------------------------------------------------

Why This Works:

Each iteration reduces the number by replacing it with the sum of its digits.
Eventually, every positive integer becomes a single-digit number after
repeated digit summation, so the loop always terminates.

--------------------------------------------------

Time Complexity: O(log n)

Each call to `getsum()` processes every digit once.
The number of digits is proportional to log₁₀(n), and only a few
iterations are required before reaching a single digit.

--------------------------------------------------

Space Complexity: O(1)

Only a few integer variables are used.

--------------------------------------------------

Pattern Used:
Digit Manipulation / Simulation

Key Learning:

1. `% 10` extracts the last digit of a number.
2. `/ 10` removes the last digit.
3. Breaking a problem into a helper function makes the solution cleaner
   and easier to understand.
*/

class Solution {
public:
    int getsum(int x)
    {
        int sum = 0;

        while(x > 0)
        {
            int digit = x % 10;
            x /= 10;
            sum += digit;
        }

        return sum;
    }

    int addDigits(int num) {

        while(num > 9)
        {
            num = getsum(num);
        }

        return num;
    }
};
