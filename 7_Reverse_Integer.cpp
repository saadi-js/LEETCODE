/*
Problem 7. Reverse Integer

Problem Statement:
Given a signed 32-bit integer x, return x with its digits reversed.

If reversing x causes the value to go outside the signed 32-bit integer
range [-2³¹, 2³¹ - 1], return 0.

Assume the environment does not allow you to store 64-bit integers
(signed or unsigned).

--------------------------------------------------

Intuition:

Reversing digits is straightforward using modulo and division:

    digit = x % 10       → extracts last digit
    x     = x / 10       → removes last digit
    rev   = rev * 10 + digit → builds reversed number

The challenge is detecting overflow BEFORE it happens,
since we cannot use a 64-bit variable to check afterward.

--------------------------------------------------

Key Idea:

Before adding the next digit to rev, check whether the operation
would overflow the 32-bit integer range.

If rev > INT_MAX / 10  → multiplying by 10 would exceed INT_MAX
If rev < INT_MIN / 10  → multiplying by 10 would exceed INT_MIN

We check BEFORE the multiplication, not after, because after
would already be overflow (undefined behavior in C++).

--------------------------------------------------

Approach:

1. Initialize rev = 0.
2. While x != 0:
   a. Extract last digit: digit = x % 10
   b. Remove last digit: x /= 10
   c. Overflow check:
        if rev > INT_MAX / 10 → return 0
        if rev < INT_MIN / 10 → return 0
   d. Append digit: rev = rev * 10 + digit
3. Return rev.

--------------------------------------------------

Example:

x = 123

Iteration 1:
digit = 3, x = 12, rev = 3

Iteration 2:
digit = 2, x = 1, rev = 32

Iteration 3:
digit = 1, x = 0, rev = 321

Output: 321

--------------------------------------------------

Negative Example:

x = -123

digit = -3, x = -12, rev = -3
digit = -2, x = -1,  rev = -32
digit = -1, x = 0,   rev = -321

Output: -321

Note: In C++, % on negative numbers preserves the sign,
so the sign handling is automatic.

--------------------------------------------------

Overflow Example:

x = 1534236469

When building the reversed number 9646324351,
the overflow check triggers and 0 is returned.

--------------------------------------------------

Why This Works:

The overflow check uses integer division to establish a safe
boundary before committing to the multiplication.

INT_MAX = 2147483647
INT_MAX / 10 = 214748364

If rev already exceeds 214748364, then rev * 10 would exceed
2147483640, and adding any digit would overflow INT_MAX.

The symmetric check applies for INT_MIN.

--------------------------------------------------

Time Complexity: O(log x)

Number of iterations equals number of digits in x.

--------------------------------------------------

Space Complexity: O(1)

Only integer variables used.

--------------------------------------------------

Pattern Used:
Math / Digit Manipulation + Overflow Detection

Key Learning:

1. Always check for overflow BEFORE the operation, not after.
2. INT_MAX / 10 is the safe threshold for multiplication overflow.
3. C++ handles negative modulo consistently (sign follows dividend).
4. This pre-check pattern appears in atoi and other integer problems.
*/



class Solution {
public:
    int reverse(int x) {

        // Stores the reversed integer
        int rev = 0;

        // Process digits one by one
        while(x != 0)
        {
            // Extract the last digit
            int digit = x % 10;

            // Remove the last digit from x
            x /= 10;

            // Check for overflow BEFORE multiplying
            // If rev * 10 would exceed INT_MAX or INT_MIN, return 0
            if(rev > INT_MAX / 10 || rev < INT_MIN / 10)
            {
                return 0;
            }

            // Append digit to reversed number
            rev = rev * 10 + digit;
        }

        return rev;
    }
};
