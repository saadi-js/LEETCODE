/*
Problem 191. Number of 1 Bits (Hamming Weight)

Problem Statement:
Given a positive integer n, write a function that returns the number
of set bits (1s) in its binary representation.
This is also known as the Hamming Weight.

--------------------------------------------------

Intuition:

A naive approach checks each bit one by one by right-shifting
and checking the least significant bit. This always takes 32
iterations regardless of how many bits are set.

A smarter approach uses the bit trick:
    n = n & (n - 1)

This clears the lowest set bit of n in each iteration,
so we only iterate as many times as there are set bits.

--------------------------------------------------

Key Idea:

The operation n & (n-1) always removes the rightmost set bit.

Why?
n     in binary: ...1 0 0 0 (some bits)
n-1   in binary: ...0 1 1 1 (flips all bits up to and including rightmost 1)
n & (n-1)      : ...0 0 0 0 (rightmost 1 and all trailing bits cleared)

So each iteration removes exactly one set bit.
Count how many iterations until n becomes 0.

--------------------------------------------------

Approach:

1. Initialize count = 0
2. While n != 0:
   - Increment count
   - n = n & (n - 1)  → clears lowest set bit
3. Return count

--------------------------------------------------

Example:

n = 11 (binary: 1011)

Iteration 1: 1011 & 1010 = 1010  → count = 1
Iteration 2: 1010 & 1001 = 1000  → count = 2
Iteration 3: 1000 & 0111 = 0000  → count = 3

Output: 3

--------------------------------------------------

Alternative Naive Approach:

while(n > 0) {
    count += n & 1;   // check LSB
    n >>= 1;          // right shift
}

This always runs 32 times.
The n & (n-1) trick runs only as many times as set bits exist.

--------------------------------------------------

Why This Works:

n - 1 flips the rightmost set bit of n to 0 and sets all lower
bits to 1. ANDing with n clears all those positions, effectively
removing the rightmost set bit in one operation.

--------------------------------------------------

Time Complexity: O(k)

Where k = number of set bits in n.
In the worst case (all 1s) this is O(32) = O(1).

--------------------------------------------------

Space Complexity: O(1)

Only a counter variable used.

--------------------------------------------------

Pattern Used:
Bit Manipulation (Brian Kernighan's Algorithm)

Key Learning:

1. n & (n-1) always clears the lowest set bit — memorize this.
2. This trick is faster than checking every bit individually.
3. The same trick is used to check if a number is a power of 2:
   if (n & (n-1)) == 0 → n is a power of 2.
4. Hamming Weight appears in problems involving bit counting,
   XOR distance, and binary representation analysis.
*/



class Solution {
public:
    int hammingWeight(int n) {

        // Counter for set bits
        int count = 0;

        // Each iteration removes the lowest set bit
        while(n != 0)
        {
            count++;

            // Clears the lowest set bit of n
            n = n & (n - 1);
        }

        return count;
    }
};
