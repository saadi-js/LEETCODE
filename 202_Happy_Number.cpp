/*
Problem 202. Happy Number

Problem Statement:
A happy number is defined by the following process:
- Starting with any positive integer, replace the number by the
  sum of the squares of its digits.
- Repeat the process until the number equals 1 (happy),
  or it loops endlessly in a cycle (not happy).

Return true if n is a happy number, false otherwise.

--------------------------------------------------

Intuition:

If we keep applying the digit-square-sum operation, one of two
things will happen:

1. The sequence reaches 1 → happy number
2. The sequence enters a cycle and never reaches 1 → not happy

The key insight is detecting when we have entered a cycle.

--------------------------------------------------

Key Idea:

Use a HashSet to store every number we have seen so far.

If a number appears again → we are in a cycle → return false.
If we reach 1 → return true.

This is essentially cycle detection using a visited set.

--------------------------------------------------

Approach:

1. Create a helper function getsum(n):
   - Extract each digit using n % 10
   - Add digit² to sum
   - Remove digit using n / 10
   - Return total sum

2. Main loop:
   - While n != 1:
       If n already in set → cycle detected → return false
       Add n to set
       n = getsum(n)
   - Return true

--------------------------------------------------

Example:

n = 19

Iteration 1: 1² + 9² = 1 + 81 = 82
Iteration 2: 8² + 2² = 64 + 4 = 68
Iteration 3: 6² + 8² = 36 + 64 = 100
Iteration 4: 1² + 0² + 0² = 1

Reached 1 → return true

--------------------------------------------------

Counter Example:

n = 2

2 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4

4 is seen again → cycle detected → return false

--------------------------------------------------

Why This Works:

Numbers that are not happy always eventually cycle back to a
previously seen value. The HashSet catches this in O(1) per lookup.

Numbers that are happy always reach 1 in a finite number of steps.

--------------------------------------------------

Alternative Approach:

Floyd's cycle detection (fast and slow pointers) can also solve
this in O(1) space, similar to Linked List Cycle detection.

--------------------------------------------------

Time Complexity: O(log n)

The number of digits decreases rapidly, so the sequence converges
or cycles in a bounded number of steps.

--------------------------------------------------

Space Complexity: O(log n)

HashSet stores the numbers seen before a cycle is detected.

--------------------------------------------------

Pattern Used:
Hashing / Cycle Detection (Visited Set)

Key Learning:

1. Whenever a process can loop indefinitely, use a HashSet to
   detect cycles by tracking seen states.
2. This exact pattern appears in Linked List Cycle and
   Find the Duplicate Number.
3. An alternative O(1) space solution exists using fast and
   slow pointers (Floyd's algorithm) on the sequence itself.
*/



class Solution {
public:

    // Helper: compute sum of squares of digits
    int getsum(int n)
    {
        int sum = 0;

        while(n > 0)
        {
            int digit = n % 10;    // extract last digit
            sum += digit * digit;  // add square of digit
            n /= 10;               // remove last digit
        }

        return sum;
    }

    bool isHappy(int n) {

        // Set to track all numbers seen so far
        unordered_set<int> st;

        // Keep transforming until we reach 1 or detect a cycle
        while(n != 1)
        {
            // If n was seen before → cycle detected → not happy
            if(st.find(n) != st.end())
            {
                return false;
            }

            // Mark current number as seen
            st.insert(n);

            // Apply transformation
            n = getsum(n);
        }

        // Reached 1 → happy number
        return true;
    }
};
