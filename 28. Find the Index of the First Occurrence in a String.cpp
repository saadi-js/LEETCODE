/*
Problem 28. Find the Index of the First Occurrence in a String

Problem Statement:

Given two strings haystack and needle, return the index of the first
occurrence of needle in haystack.

If needle is not part of haystack, return -1.

--------------------------------------------------

Intuition:

To find the first occurrence of a substring, we can try matching
the needle starting from every possible position in the haystack.

For each starting index:

- Compare characters one by one.
- If every character matches, return the starting index.
- Otherwise, move to the next possible starting position.

This is known as the brute-force substring matching approach.

--------------------------------------------------

Key Idea:

Step 1: Consider every valid starting position in the haystack.
Step 2: Compare the needle character by character.
Step 3: If all characters match, return the starting index.
Step 4: If no match is found after checking every position, return -1.

--------------------------------------------------

Approach:

1. Let:
   - m = length of haystack
   - n = length of needle
2. Traverse every possible starting index from 0 to m - n.
3. For each index:
   - Compare the characters of haystack and needle.
   - Continue while they match.
4. If all characters of the needle are matched:
   - Return the current starting index.
5. If no occurrence is found, return -1.

--------------------------------------------------

Example:

Input:

haystack = "sadbutsad"
needle = "sad"

Process:

Start at index 0:

s == s ✔
a == a ✔
d == d ✔

Entire needle matched.

Output:

0

--------------------------------------------------

Counter Example:

Input:

haystack = "leetcode"
needle = "leeto"

Process:

Start at index 0:

l == l ✔
e == e ✔
e == e ✔
t == t ✔

Next comparison:

c != o ✘

Continue checking the remaining positions.

No complete match is found.

Output:

-1

--------------------------------------------------

Why This Works:

The algorithm checks every possible position where the needle could
begin.

For each position, it verifies whether every character matches.

If a complete match exists, the first successful comparison returns
the correct index.

If every starting position fails, the needle is not present.

--------------------------------------------------

Time Complexity: O((m - n + 1) × n)

Where:
- m = length of haystack
- n = length of needle

In the worst case, each starting position compares all characters
of the needle.

--------------------------------------------------

Space Complexity: O(1)

Only a few index variables are used.

--------------------------------------------------

Pattern Used:
Strings / Brute Force Pattern Matching

Key Learning:

1. Brute-force substring matching checks every possible starting position.
2. The outer loop selects a starting index, while the inner loop verifies the match.
3. Restricting the outer loop to `m - n` prevents out-of-bounds access.
4. Although algorithms like KMP solve this problem in O(m + n), the brute-force approach is simple, intuitive, and sufficient for many interview questions.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {

        int m = haystack.size();
        int n = needle.size();

        // Try every possible starting position
        for(int i = 0; i <= m - n; i++)
        {
            int j = i;
            int k = 0;

            // Compare characters
            while(k < n && haystack[j] == needle[k])
            {
                j++;
                k++;
            }

            // Entire needle matched
            if(k == n)
            {
                return i;
            }
        }

        return -1;
    }
};
