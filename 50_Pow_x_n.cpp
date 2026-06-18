/*
Problem 50. Pow(x, n)

Problem Statement:
Implement pow(x, n), which calculates x raised to the power n (xⁿ).

--------------------------------------------------

Intuition:

A naive approach would multiply x by itself n times.

For example:
x = 2, n = 10

2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2

This takes O(n) time.

We can do much better using Binary Exponentiation (Fast Exponentiation).

Observation:

x^10
= x^(1010₂)

Instead of multiplying x ten times, we repeatedly square x.

Example:

2^10

2^10 = 2^8 × 2^2

By continuously squaring:
2 → 4 → 16 → 256 ...

we can build the answer using only O(log n) operations.

--------------------------------------------------

Approach:

1. Store n in a long variable.
   This prevents overflow when n = INT_MIN.

2. Handle special cases:
   - n = 0
   - x = 0
   - x = 1

3. If n is negative:
   - Convert x into 1/x.
   - Make exponent positive.

4. While exponent is greater than 0:
   - If exponent is odd:
       Multiply answer by current x.
   - Square x.
   - Divide exponent by 2.

5. Return the final answer.

--------------------------------------------------

Example:

x = 2
n = 10

Binary representation of 10:

1010

Step 1:
answer = 1

10 is even
x = 4

5 is odd
answer = 4

x = 16

2 is even
x = 256

1 is odd
answer = 4 × 256 = 1024

Result = 1024

--------------------------------------------------

Why This Works:

Every exponent can be represented as a sum of powers of two.

Example:

13 = 8 + 4 + 1

Therefore:

x^13
= x^8 × x^4 × x^1

Binary exponentiation efficiently extracts these powers by repeatedly
checking whether the current bit is set.

--------------------------------------------------

Handling Negative Powers:

Example:

2^-3

= 1 / (2^3)

Instead of directly computing a negative power:

x = 1/x

and

n = -n

Then compute normally.

--------------------------------------------------

Important Edge Case:

When n = INT_MIN (-2147483648)

Doing:

n = -n

causes overflow because INT_MAX is only 2147483647.

To avoid this:

Store n inside a long variable before negating.

--------------------------------------------------

Time Complexity: O(log n)

The exponent is divided by 2 during every iteration.

--------------------------------------------------

Space Complexity: O(1)

Only a few variables are used.

--------------------------------------------------

Pattern Used:
Binary Exponentiation (Fast Power)

Key Learning:
1. Any exponent can be processed using its binary representation.
2. Repeated squaring reduces O(n) to O(log n).
3. Always handle INT_MIN carefully when negating exponents.
4. Binary Exponentiation is frequently used in competitive programming,
   mathematics, and modular arithmetic problems.
*/


class Solution {
public:
    double myPow(double x, int n) {

        // Store exponent in a long variable
        // to safely handle INT_MIN
        long binary = n;

        // Stores the final answer
        double answer = 1;

        // Any number raised to power 0 is 1
        if(n == 0) return 1.0;

        // 0 raised to any positive power is 0
        if(x == 0) return 0.0;

        // 1 raised to any power is always 1
        if(x == 1) return 1.0;

        // Special case checks for x = 1
        // (These conditions are redundant because x == 1
        // is already handled above, but keeping them as-is)
        if(x == 1 && n % 2 == 0) return 1.0;
        if(x == 1 && n % 2 != 0) return -1.0;

        // Handle negative exponents
        if(n < 0)
        {
            // Convert x^(-n) into (1/x)^n
            x = 1 / x;

            // Make exponent positive
            binary = -binary;
        }

        // Perform Binary Exponentiation
        while(binary > 0)
        {
            // If current bit is set (odd exponent)
            // include current power in the answer
            if(binary % 2 == 1)
            {
                answer = answer * x;
            }

            // Move to the next power by squaring
            x = x * x;

            // Shift exponent right by one bit
            // equivalent to dividing by 2
            binary = binary / 2;
        }

        // Return final computed power
        return answer;
    }
};
