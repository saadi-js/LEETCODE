/*
Problem 9. Palindrome Number

Problem Statement:

Given an integer x, return true if x is a palindrome, and false otherwise.

An integer is a palindrome when it reads the same forward and backward.

--------------------------------------------------

Intuition:

A straightforward approach is to convert the integer into a string
and then check if the string is a palindrome.

This simplifies digit handling and avoids manual math operations.

--------------------------------------------------

Key Idea:

A palindrome property means:

- First character == last character
- Second character == second last character
- And so on...

So we use a two-pointer technique on the string representation.

--------------------------------------------------

Approach:

1. Convert integer x into string using to_string().
2. Use two pointers:
   - start → beginning of string
   - end → end of string
3. While start < end:
   - If characters mismatch → return false
   - Otherwise move both pointers inward
4. If loop completes → return true

--------------------------------------------------

Example:

x = 121

String = "121"

Compare:
1 == 1 → ok
2 (middle) → stop

Result = true

--------------------------------------------------

Negative Numbers:

Example:
x = -121 → "-121"

Since '-' is included, mismatch occurs immediately,
so result is always false for negatives.

--------------------------------------------------

Why This Works:

String conversion allows direct symmetry comparison,
making the problem identical to standard palindrome checking.

--------------------------------------------------

Time Complexity: O(d)

Where d = number of digits in x

--------------------------------------------------

Space Complexity: O(d)

Due to string conversion.

--------------------------------------------------

Pattern Used:
Two Pointers (String Palindrome Check)

Key Learning:

1. Converting numbers to strings simplifies digit problems.
2. Two-pointer technique is universal for palindrome checks.
3. Negative numbers are automatically handled via string form.
*/




class Solution {
public:
    bool isPalindrome(int x) {

        // Convert integer to string for easy comparison
        string s = to_string(x);

        // Left pointer
        int start = 0;

        // Right pointer
        int end = s.length() - 1;

        // Compare characters from both ends
        while(start < end)
        {
            // If mismatch found, not a palindrome
            if(s[start] != s[end])
            {
                return false;
            }

            // Move pointers inward
            start++;
            end--;
        }

        // If all matched, it's a palindrome
        return true;
    }
};
