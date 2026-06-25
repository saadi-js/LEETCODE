/*
Problem 1662. Check If Two String Arrays are Equivalent

Problem Statement:
Given two string arrays word1 and word2, return true if the two
arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated
in order forms that string.

--------------------------------------------------

Intuition:

The simplest approach is to concatenate all strings in each array
and compare the resulting strings.

Since the problem only asks whether they represent the same string,
building the full concatenation and comparing is both correct
and straightforward.

--------------------------------------------------

Key Idea:

Concatenate all strings in word1 into s1.
Concatenate all strings in word2 into s2.
Return s1 == s2.

--------------------------------------------------

Approach:

1. Initialize s1 = "", s2 = "".
2. For each string in word1, append to s1.
3. For each string in word2, append to s2.
4. Return s1 == s2.

--------------------------------------------------

Example 1:

word1 = ["ab","c"]
word2 = ["a","bc"]

s1 = "ab" + "c"  = "abc"
s2 = "a"  + "bc" = "abc"

s1 == s2 → return true

--------------------------------------------------

Example 2:

word1 = ["a","cb"]
word2 = ["ab","c"]

s1 = "a"  + "cb" = "acb"
s2 = "ab" + "c"  = "abc"

s1 != s2 → return false

--------------------------------------------------

Why This Works:

String concatenation is associative — the final string depends
only on the characters and their order, not how they are split
across array elements. So comparing the full concatenations
correctly captures whether both arrays represent the same string.

--------------------------------------------------

Alternative (Two Pointer without full concatenation):

Use four pointers (word index and char index for each array)
to compare characters one by one without building the full string.
This avoids O(n) extra space but is more complex to implement.

--------------------------------------------------

Time Complexity: O(n + m)

Where n = total characters in word1, m = total in word2.

--------------------------------------------------

Space Complexity: O(n + m)

Two concatenated strings stored in memory.

--------------------------------------------------

Pattern Used:
String / Concatenation and Comparison

Key Learning:

1. For "do these arrays represent the same string" problems,
   full concatenation is the simplest and most readable approach.
2. The two-pointer alternative is worth knowing for follow-up
   questions about reducing space complexity.
3. String += operator in C++ efficiently appends strings.
*/



class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        // Build full string from word1
        string s1 = "";

        for(string s : word1)
        {
            s1 += s;
        }

        // Build full string from word2
        string s2 = "";

        for(string s : word2)
        {
            s2 += s;
        }

        // Compare both concatenated strings
        return s1 == s2;
    }
};
