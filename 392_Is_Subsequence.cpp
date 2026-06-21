/*
Problem 392. Is Subsequence

Problem Statement:
Given two strings s and t, determine if s is a subsequence of t.

A subsequence is a string that can be derived from another string
by deleting some (or no) characters without changing the relative order
of remaining characters.

Intuition:
We need to check whether all characters of s appear in t in order.
We cannot reorder or reuse characters, only skip over irrelevant ones.

Key Idea:
Use two pointers:
- i → pointer for s
- j → pointer for t

Move through t and try to match characters of s in order.

Approach:
1. Initialize i = 0, j = 0
2. Traverse t using j
3. If s[i] == t[j]:
   - move both pointers
4. Else:
   - move only j (skip t[j])
5. If i reaches end of s → all characters matched

Example:

s = "abc"
t = "ahbgdc"

Matching process:
a → a ✔
b → b ✔
c → c ✔

Output: true

Why This Works:
We greedily match characters of s in order while scanning t once.
Skipping is allowed in t, but order must be preserved.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Two Pointers / Greedy Matching

Key Learning:
Subsequence problems are solved by linear scan with greedy matching.
*/




class Solution {
public:

    bool isSubsequence(string s, string t) {

        // Pointer for string s
        int i = 0;

        // Pointer for string t
        int j = 0;

        // Traverse string t
        while(i < s.size() && j < t.size())
        {
            // If characters match, move both pointers
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                // Otherwise skip character in t
                j++;
            }
        }

        // If all characters of s were matched
        if(i == s.size())
        {
            return true;
        }

        return false;
    }
};
