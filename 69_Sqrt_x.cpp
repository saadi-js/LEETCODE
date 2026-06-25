/*
Problem 69. Sqrt(x)

Problem Statement:
Given a non-negative integer x, return the square root of x rounded
down to the nearest integer. The returned integer should be
non-negative as well.

You must not use any built-in exponent function or operator.

--------------------------------------------------

Intuition:

One approach is binary search — search for the largest integer k
such that k² <= x. That gives O(log x).

This solution uses Newton's Method (Newton-Raphson), an iterative
numerical technique that converges to the square root very quickly.

--------------------------------------------------

Key Idea (Newton's Method):

To find sqrt(x), we want to solve: f(t) = t² - x = 0

Newton's iteration formula:
    t_new = (t_old + x / t_old) / 2

Starting from an initial guess x0 = x, each iteration produces
a better approximation of sqrt(x).

We stop when the difference between consecutive approximations
is less than 1 (since we need an integer result).

--------------------------------------------------

Approach:

1. Handle edge case: x == 0 → return 0.
2. Initialize x0 = x (initial guess).
3. Compute x1 = (x0 + x/x0) / 2.
4. While |x0 - x1| >= 1:
   - x0 = x1
   - x1 = (x0 + x/x0) / 2
5. Return (int)x1 (floor of the approximation).

--------------------------------------------------

Example:

x = 8

x0 = 8
x1 = (8 + 8/8) / 2 = (8 + 1) / 2 = 4.5
x1 = (4.5 + 8/4.5) / 2 = (4.5 + 1.78) / 2 = 3.14
x1 = (3.14 + 8/3.14) / 2 = (3.14 + 2.55) / 2 = 2.83

|3.14 - 2.83| < 1 → stop

Output: (int)2.83 = 2

Verify: 2² = 4 <= 8, 3² = 9 > 8 ✓

--------------------------------------------------

Alternative (Binary Search):

int left = 0, right = x;
while(left <= right) {
    long mid = left + (right - left) / 2;
    if(mid * mid == x) return mid;
    else if(mid * mid < x) { ans = mid; left = mid + 1; }
    else right = mid - 1;
}
return ans;

Binary search is arguably cleaner and avoids floating point.

--------------------------------------------------

Why This Works:

Newton's method converges quadratically — each iteration roughly
doubles the number of correct digits. For integer square roots,
convergence happens in very few iterations.

The cast to int naturally floors the result as required.

--------------------------------------------------

Time Complexity: O(log x)

Newton's method converges in O(log x) iterations.

--------------------------------------------------

Space Complexity: O(1)

Only a few floating point variables used.

--------------------------------------------------

Pattern Used:
Math / Newton's Method (Numerical Iteration)

Key Learning:

1. Newton's method is a powerful numerical technique for root-finding.
2. Binary search is the cleaner alternative for integer problems.
3. Always handle x == 0 separately to avoid division by zero.
4. Casting double to int floors the value — equivalent to floor().
*/



class Solution {
public:
    int mySqrt(int x) {

        // Edge case: sqrt(0) = 0
        if(x == 0) return 0;

        // Initial guess
        double x0 = x;

        // First Newton iteration
        double x1 = (x0 + x / x0) / 2.0;

        // Iterate until approximation stabilizes within 1
        while(abs(x0 - x1) >= 1)
        {
            x0 = x1;
            x1 = (x0 + x / x0) / 2.0;
        }

        // Floor the result by casting to int
        return (int)x1;
    }
};
