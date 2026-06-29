/*
Problem 680. Valid Palindrome II

Problem Statement:

Given a string s, return true if it can become a palindrome after
deleting at most one character.

Otherwise, return false.

--------------------------------------------------

Intuition:

Normally, to check whether a string is a palindrome, we compare
characters from both ends using two pointers.

If all corresponding characters match, the string is already a palindrome.

The only complication arises when we encounter the first mismatch.

Since we are allowed to delete at most one character, there are only
two possible choices:

1. Delete the left mismatched character.
2. Delete the right mismatched character.

If either resulting substring is a palindrome, the answer is true.

--------------------------------------------------

Key Idea:

Step 1: Use two pointers from both ends.
Step 2: Continue while characters match.
Step 3: On the first mismatch:
        - Check if skipping the left character forms a palindrome.
        - Check if skipping the right character forms a palindrome.
Step 4: If either check succeeds, return true.
Step 5: Otherwise, return false.

--------------------------------------------------

Approach:

1. Initialize:
   - left = 0
   - right = n - 1
2. Compare characters while left < right.
3. If characters match:
   - Move both pointers inward.
4. If a mismatch occurs:
   - Check palindrome(left + 1, right).
   - Check palindrome(left, right - 1).
   - Return true if either is valid.
5. If the traversal completes without requiring more than one deletion,
   return true.

--------------------------------------------------

Example:

Input:

s = "abca"

Compare:

a == a ✔

b != c ✘

Two possibilities:

Skip 'b'

"aca"

Palindrome ✔

Skip 'c'

"aba"

Palindrome ✔

Output:

true

--------------------------------------------------

Counter Example:

Input:

s = "abc"

Compare:

a != c ✘

Skip 'a'

"bc"

Not a palindrome

Skip 'c'

"ab"

Not a palindrome

Output:

false

--------------------------------------------------

Why This Works:

The first mismatch is the only place where a deletion can help.

Trying both possible deletions guarantees that we explore every valid
way to remove one character.

The helper function verifies whether the remaining substring is a
palindrome.

If either choice succeeds, the original string can become a palindrome
after deleting at most one character.

--------------------------------------------------

Time Complexity: O(n)

The main traversal is O(n).

The helper function may scan the remaining substring once after the
first mismatch.

Overall complexity remains O(n).

--------------------------------------------------

Space Complexity: O(1)

Only a few pointer variables are used.

--------------------------------------------------

Pattern Used:
Two Pointers / Greedy

Key Learning:

1. Two pointers are the standard technique for palindrome problems.
2. At the first mismatch, only two possibilities need to be checked.
3. A helper function simplifies palindrome verification.
4. Greedily handling the first mismatch leads to an optimal O(n) solution.
*/

class Solution {
public:

    bool palind(string &s, int left, int right)
    {
        while(left < right)
        {
            if(s[left] != s[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                return palind(s, left + 1, right) ||
                       palind(s, left, right - 1);
            }
        }

        return true;
    }
};
