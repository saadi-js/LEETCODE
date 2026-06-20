/*
Problem 1281. Subtract the Product and Sum of Digits of an Integer

Problem Statement:
Given an integer n, return the difference between:
- Product of its digits
- Sum of its digits

Intuition:
We decompose the number digit by digit using modulo and division.
At each step, we accumulate:
- Sum of digits
- Product of digits

Finally, we return (product - sum).

Key Idea:
Digit extraction using:
- n % 10 → last digit
- n / 10 → remove last digit

Approach:
1. Initialize sum = 0, product = 1
2. While n > 0:
   - Extract digit = n % 10
   - Add digit to sum
   - Multiply digit into product
   - Remove digit from n
3. Return product - sum

Example:
n = 234

Digits: 2, 3, 4

Sum = 2 + 3 + 4 = 9
Product = 2 * 3 * 4 = 24

Result = 24 - 9 = 15

Why This Works:
Each digit is independent, so we can process them sequentially
using arithmetic operations.

Time Complexity: O(d)
Space Complexity: O(1)

Pattern Used:
Digit Manipulation / Math Simulation

Key Learning:
Whenever a problem involves digits of a number,
use modulo (%) and division (/) to iterate efficiently.
*/



class Solution {
public:

    int subtractProductAndSum(int n) {

        // Initialize sum of digits
        int sum = 0;

        // Initialize product of digits
        int prod = 1;

        // Process each digit of the number
        while(n > 0)
        {
            // Extract last digit
            int digit = n % 10;

            // Add digit to sum
            sum += digit;

            // Multiply digit into product
            prod *= digit;

            // Remove last digit
            n = n / 10;
        }

        // Return difference between product and sum
        return prod - sum;
    }
};
