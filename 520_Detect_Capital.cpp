/*
Problem 520. Detect Capital

Problem Statement:
We define the usage of capital letters in a word to be correct if:
1. All letters are capital (e.g. "USA")
2. All letters are lowercase (e.g. "leetcode")
3. Only the first letter is capital (e.g. "Google")

Given a string word, return true if the capital usage is correct.

--------------------------------------------------

Intuition:

Instead of checking all three cases separately with string
comparisons, we can reduce the problem to a single observation:

Count how many capital letters exist in the word, then check
which of the three valid patterns that count matches.

--------------------------------------------------

Key Idea:

Count capital letters → cap

Three valid conditions:
1. cap == 0         → all lowercase
2. cap == n         → all uppercase
3. cap == 1 AND word[0] is uppercase → only first letter capital

If none of these hold → return false.

--------------------------------------------------

Approach:

1. Count uppercase letters in the word.
2. Check three conditions:
   - If cap == 0 → valid (all lowercase)
   - If cap == n → valid (all uppercase)
   - If cap == 1 AND word[0] is uppercase → valid (title case)
3. Otherwise return false.

--------------------------------------------------

Example 1:

word = "USA"
cap = 3, n = 3
cap == n → return true

--------------------------------------------------

Example 2:

word = "Google"
cap = 1, n = 6
cap == 1 AND word[0] == 'G' (uppercase) → return true

--------------------------------------------------

Example 3:

word = "FlaG"
cap = 2, n = 4
None of the three conditions match → return false

--------------------------------------------------

Why This Works:

All valid capital patterns are fully described by the count of
uppercase letters and the case of the first character.
No need to compare substrings or iterate twice.

--------------------------------------------------

Time Complexity: O(n)

Single pass to count uppercase letters.

--------------------------------------------------

Space Complexity: O(1)

Only a counter variable used.

--------------------------------------------------

Pattern Used:
String / Character Property Counting

Key Learning:

1. Reduce multi-case condition checks to a single metric (count).
2. Character range checks ('A' to 'Z') are faster than library
   functions in some contexts and make the logic explicit.
3. When a problem has exactly 3 valid patterns, enumerate all 3
   and return false for everything else.
*/



class Solution {
public:
    bool detectCapitalUse(string word) {

        // Length of the word
        int n = word.size();

        // Count of uppercase letters
        int cap = 0;

        for(char c : word)
        {
            // Check if character is uppercase
            if(c >= 'A' && c <= 'Z')
            {
                cap++;
            }
        }

        // Condition 1: all lowercase
        if(cap == 0) return true;

        // Condition 2: all uppercase
        if(cap == n) return true;

        // Condition 3: only first letter is uppercase
        if(cap == 1 && word[0] >= 'A' && word[0] <= 'Z') return true;

        // None of the valid patterns matched
        return false;
    }
};
