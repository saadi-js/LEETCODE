/*
Problem 2235. Add Two Integers

Problem Statement:

Given two integers num1 and num2, return their sum.

--------------------------------------------------

Intuition:

This is a straightforward arithmetic problem.
Since the task is simply to add two integers, no special data structures
or algorithms are required.

--------------------------------------------------

Key Idea:

Use the addition (+) operator to compute the sum of the two numbers
and return the result.

--------------------------------------------------

Approach:

1. Receive the two integers as input.
2. Add them using the '+' operator.
3. Return the resulting sum.

--------------------------------------------------

Example:

Input:
num1 = 12
num2 = 5

Calculation:
12 + 5 = 17

Output:
17

--------------------------------------------------

Counter Example:

Input:
num1 = -10
num2 = 4

Calculation:
-10 + 4 = -6

Output:
-6

--------------------------------------------------

Why This Works:

The '+' operator performs integer addition and directly computes
the required result.

--------------------------------------------------

Time Complexity: O(1)

Only one arithmetic operation is performed.

--------------------------------------------------

Space Complexity: O(1)

No extra space is used.

--------------------------------------------------

Pattern Used:
Basic Arithmetic

Key Learning:

1. Simple problems often test understanding of function syntax and return values.
2. Integer addition using the '+' operator executes in constant time.
3. Always return the computed value directly when no intermediate processing is required.
*/

class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};
