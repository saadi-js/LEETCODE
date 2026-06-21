/*
Problem 8. String to Integer (atoi)

Problem Statement:
Implement the myAtoi(string s) function, which converts a string to a
32-bit signed integer (similar to C/C++'s atoi function).

The algorithm follows these rules in order:
1. Skip leading whitespace.
2. Determine sign ('+' or '-'). Default is positive.
3. Read digits until a non-digit character or end of string.
4. Clamp the result to [-2³¹, 2³¹ - 1] if it overflows.
5. Return the integer.

--------------------------------------------------

Intuition:

This is a simulation problem — we follow the stated rules step by step.

The tricky parts are:
- Handling optional sign correctly
- Stopping digit parsing at the first non-digit character
- Clamping early to avoid overflow before the final return

--------------------------------------------------

Key Idea:

Process the string in exactly four phases:

Phase 1 → Skip spaces
Phase 2 → Read optional sign
Phase 3 → Build number digit by digit
Phase 4 → Clamp to INT_MAX or INT_MIN if overflow occurs

Using a long long for accumulation lets us detect overflow
by comparing against INT_MAX and INT_MIN before casting.

--------------------------------------------------

Approach:

1. Initialize i = 0, sign = 1, num = 0.
2. Skip leading spaces: while s[i] == ' ', i++.
3. Read sign:
   - If s[i] == '-' → sign = -1, i++
   - If s[i] == '+' → i++
4. Build number:
   - While s[i] is a digit:
       num = num * 10 + (s[i] - '0')
       If sign * num > INT_MAX → return INT_MAX
       If sign * num < INT_MIN → return INT_MIN
       i++
5. Return (int)(sign * num)

--------------------------------------------------

Example 1:

s = "42"

Skip spaces: none
Sign: none (default +1)
Digits: 4, 2 → num = 42

Output: 42

--------------------------------------------------

Example 2:

s = "   -42"

Skip spaces: 3 spaces skipped
Sign: '-' → sign = -1
Digits: 4, 2 → num = 42

Output: -42

--------------------------------------------------

Example 3:

s = "4193 with words"

Digits: 4, 1, 9, 3
Space encountered → stop

Output: 4193

--------------------------------------------------

Example 4:

s = "91283472332"

During digit parsing:
sign * num exceeds INT_MAX → clamp → return INT_MAX (2147483647)

--------------------------------------------------

Why This Works:

Each phase is handled independently in strict order,
matching the problem specification exactly.

Early clamping during digit accumulation prevents actual overflow
of the long long variable for reasonable-length inputs.

isdigit() is a standard library function that returns true for '0'-'9'.

--------------------------------------------------

Time Complexity: O(n)

Single pass through the string.

--------------------------------------------------

Space Complexity: O(1)

Only a fixed number of variables used.

--------------------------------------------------

Pattern Used:
String Parsing / Simulation (Multi-phase processing)

Key Learning:

1. Simulation problems must follow the stated rules in exact order.
2. Use long long for intermediate accumulation to safely detect overflow.
3. Clamp inside the digit-building loop, not just at the end.
4. isdigit() is cleaner than manual range checks for digit detection.
5. This pattern of "skip → sign → digits → clamp" is the canonical
   atoi implementation and appears frequently in system design interviews.
*/



class Solution {
public:
    int myAtoi(string s) {

        // Index pointer, length, sign, and accumulated number
        int i = 0, n = s.size();
        int sign = 1;
        long long num = 0;

        // Phase 1: Skip leading whitespace
        while(i < n && s[i] == ' ')
        {
            i++;
        }

        // Phase 2: Read optional sign character
        if(i < n && (s[i] == '+' || s[i] == '-'))
        {
            if(s[i] == '-') sign = -1;
            i++;
        }

        // Phase 3: Build the number digit by digit
        while(i < n && isdigit(s[i]))
        {
            // Append current digit to accumulated number
            num = num * 10 + (s[i] - '0');

            // Phase 4: Clamp early to avoid overflow
            if(sign * num > INT_MAX) return INT_MAX;
            if(sign * num < INT_MIN) return INT_MIN;

            i++;
        }

        // Apply sign and cast to int
        return (int)(sign * num);
    }
};
