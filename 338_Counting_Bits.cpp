/*
Problem 338. Counting Bits

Problem Statement:
Given an integer n, return an array ans of length n + 1 such that
for each i (0 <= i <= n), ans[i] is the number of 1s in the
binary representation of i.

--------------------------------------------------

Intuition:

A brute force approach counts bits for every number from 0 to n
individually. If we use the n & (n-1) trick from Hamming Weight,
each count takes O(k) where k is the number of set bits.

That is exactly what this solution does — reuses the countone()
helper for each number from 0 to n.

--------------------------------------------------

Key Idea:

For each i from 0 to n:
- Count set bits using Brian Kernighan's trick: x = x & (x-1)
- Push the count into the result array

--------------------------------------------------

Helper Function (countone):

Uses n & (n-1) to repeatedly clear the lowest set bit.
Each iteration removes one set bit, so the loop runs exactly
as many times as there are set bits.

--------------------------------------------------

Approach:

1. Create result array ans.
2. For each i from 0 to n:
   - Call countone(i) to get number of set bits
   - Append to ans
3. Return ans.

--------------------------------------------------

Example:

n = 5

i = 0 → 0000 → 0 bits
i = 1 → 0001 → 1 bit
i = 2 → 0010 → 1 bit
i = 3 → 0011 → 2 bits
i = 4 → 0100 → 1 bit
i = 5 → 0101 → 2 bits

Output: [0,1,1,2,1,2]

--------------------------------------------------

Optimal Alternative (DP approach):

There is an O(n) solution using dynamic programming:

ans[i] = ans[i >> 1] + (i & 1)

i >> 1 right-shifts i by 1 (same as i/2).
The bit count of i equals the bit count of i/2
plus 1 if i is odd (has a trailing 1 bit).

This avoids the inner loop entirely.

--------------------------------------------------

Time Complexity: O(n log n)

For each of the n+1 numbers, counting bits takes O(log i).

--------------------------------------------------

Space Complexity: O(1)

Excluding the output array.

--------------------------------------------------

Pattern Used:
Bit Manipulation (Hamming Weight per element)

Key Learning:

1. Reusing a helper function keeps the solution clean and readable.
2. The DP approach ans[i] = ans[i>>1] + (i&1) is O(n) and
   worth knowing as the optimal solution.
3. n & (n-1) clears the lowest set bit — fundamental bit trick.
4. Building on previously solved problems (191. Number of 1 Bits)
   is a natural progression.
*/



class Solution {
public:

    // Helper: count set bits using Brian Kernighan's trick
    int countone(int x)
    {
        int count = 0;

        // Each iteration removes the lowest set bit
        while(x)
        {
            x = x & (x - 1);
            count++;
        }

        return count;
    }

    vector<int> countBits(int n) {

        // Result array of size n+1
        vector<int> ans;

        // Count bits for every number from 0 to n
        for(int i = 0; i <= n; i++)
        {
            ans.push_back(countone(i));
        }

        return ans;
    }
};
