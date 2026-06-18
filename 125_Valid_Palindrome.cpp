/*
Problem 125. Valid Palindrome

Problem Statement:

Given a string s, determine if it is a palindrome, considering only
alphanumeric characters and ignoring cases.

A palindrome reads the same forward and backward after normalization.

--------------------------------------------------

Intuition:

A normal palindrome check compares characters from both ends.

However, this problem adds constraints:
- Ignore non-alphanumeric characters
- Ignore case differences

So we first logically "filter" the string while comparing.

--------------------------------------------------

Key Idea:

Use Two Pointers:

- One pointer starts from the beginning (st)
- One pointer starts from the end (end)

We move both pointers inward while:
- Skipping non-alphanumeric characters
- Comparing characters in lowercase form

--------------------------------------------------

Approach:

1. Initialize two pointers:
   - st = 0
   - end = s.length() - 1

2. While st < end:
   - Skip invalid characters from left
   - Skip invalid characters from right
   - Compare characters using lowercase
   - If mismatch → return false
   - Otherwise move both pointers inward

3. If loop completes → string is palindrome

--------------------------------------------------

Helper Function:

isAlphaNumeric(ch):
Returns true if character is:
- digit (0–9)
- lowercase letter (a–z)
- uppercase letter (A–Z)

--------------------------------------------------

Example:

s = "A man, a plan, a canal: Panama"

Filtered:
"amanaplanacanalpanama"

Comparison:
Same forward and backward → valid palindrome

--------------------------------------------------

Why This Works:

Instead of creating a new cleaned string,
we simulate the cleaned version using two pointers.

This avoids extra space and unnecessary preprocessing.

--------------------------------------------------

Time Complexity: O(n)

Each character is visited at most once.

--------------------------------------------------

Space Complexity: O(1)

No extra data structures used.

--------------------------------------------------

Pattern Used:
Two Pointers + String Filtering

Key Learning:

1. Always consider in-place filtering with two pointers.
2. Avoid creating extra strings when skipping characters.
3. Case normalization is important in string comparison problems.
4. Very common pattern in string interview questions.
*/



class Solution {
public:

    // Helper function to check if character is alphanumeric
    bool isAlphaNumeric(char ch)
    {
        // Check if character is digit or uppercase/lowercase letter
        if(ch >= '0' && ch <= '9' ||
           ch >= 'a' && ch <= 'z' ||
           ch >= 'A' && ch <= 'Z')
        {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {

        // Left pointer
        int st = 0;

        // Right pointer
        int end = s.length() - 1;

        // Traverse until pointers meet
        while(st < end)
        {
            // Skip non-alphanumeric characters from left side
            if(!isAlphaNumeric(s[st]))
            {
                st++;
                continue;
            }

            // Skip non-alphanumeric characters from right side
            if(!isAlphaNumeric(s[end]))
            {
                end--;
                continue;
            }

            // Compare characters in lowercase form
            if(tolower(s[st]) != tolower(s[end]))
            {
                return false;
            }

            // Move both pointers inward
            st++;
            end--;
        }

        // If all checks pass, it's a valid palindrome
        return true;
    }
};
