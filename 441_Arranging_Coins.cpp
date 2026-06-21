/*
Problem 441. Arranging Coins

Problem Statement:
You are given n coins and you build a staircase with them.
The ith row of the staircase requires i coins.

Return the total number of full staircase rows that can be formed.

Intuition:
We need to find the maximum k such that:

1 + 2 + 3 + ... + k ≤ n

This is a classic arithmetic progression problem:
Sum = k(k+1)/2

So we are searching for the largest k where:
k(k+1)/2 ≤ n

Key Idea:
This is a monotonic condition:
- If k is valid → all smaller k are valid
- If k is invalid → all larger k are invalid

So we use binary search on k.

Approach:
1. Set search space:
   - left = 0
   - right = n
2. For each mid:
   - compute triangular sum: mid(mid+1)/2
3. If sum ≤ n:
   - store mid as answer
   - move right side higher (try bigger k)
4. Else:
   - decrease right
5. Return ans

Example:

n = 5

k = 1 → 1
k = 2 → 3
k = 3 → 6 (invalid)

Answer = 2

Why This Works:
The function k(k+1)/2 is strictly increasing,
so binary search can efficiently find boundary.

Time Complexity: O(log n)
Space Complexity: O(1)

Pattern Used:
Binary Search on Answer / Mathematical Monotonic Function

Key Learning:
When solving “maximum k such that condition holds”,
convert equation and apply binary search on k.
*/


class Solution {
public:

    int arrangeCoins(int n) {

        // Binary search range for number of rows
        int left = 0, right = n;

        // Stores final answer
        int ans;

        // Binary search on k (rows)
        while(left <= right)
        {
            // Mid = candidate number of complete rows
            long long mid = left + (right - left) / 2;

            // Total coins needed for mid rows
            long long curr = mid * (mid + 1) / 2;

            // If we can build at least mid rows
            if(curr <= n)
            {
                // Store valid answer
                ans = mid;

                // Try to build more rows
                left = mid + 1;
            }
            else
            {
                // Too many coins required, reduce rows
                right = mid - 1;
            }
        }

        return ans;
    }
};
