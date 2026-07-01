/*
Problem 205. Isomorphic Strings

Problem Statement:
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to
get t, where:
- Each character maps to exactly one character
- No two characters map to the same character
- A character may map to itself

--------------------------------------------------

Intuition:

A single map from s→t is not enough because it allows two different
s characters to map to the same t character.

We need a bidirectional mapping:
- mp1: s → t (each s char maps to a specific t char)
- mp2: t → s (each t char maps back to a specific s char)

If either mapping is violated → not isomorphic.

--------------------------------------------------

Key Idea:

For each position i:
- If s[i] already mapped AND mp1[s[i]] != t[i] → conflict → false
- If t[i] already mapped AND mp2[t[i]] != s[i] → conflict → false
- Otherwise establish both mappings

--------------------------------------------------

Approach:

1. Initialize mp1 (char→char) and mp2 (char→char).
2. For each index i:
   - Check mp1: if s[i] exists and maps to wrong t[i] → false
   - Check mp2: if t[i] exists and maps to wrong s[i] → false
   - Set mp1[s[i]] = t[i] and mp2[t[i]] = s[i]
3. Return true.

--------------------------------------------------

Example:

s = "egg", t = "add"

i=0: e→a, a→e (establish)
i=1: g→d, d→g (establish)
i=2: g already maps to d, t[2]=d ✓; d already maps to g, s[2]=g ✓

Output: true

--------------------------------------------------

Counter Example:

s = "foo", t = "bar"

i=0: f→b, b→f (establish)
i=1: o→a, a→o (establish)
i=2: o already maps to a, t[2]=r ≠ a → return false

Output: false

--------------------------------------------------

Why Two Maps?

s = "ab", t = "aa"

mp1 only: a→a, b→a (no conflict in mp1)
But b maps to a which a already maps to — not isomorphic.
mp2 catches this: a→a established, then a→b conflicts → false.

--------------------------------------------------

Time Complexity: O(n)

Single pass through both strings.

--------------------------------------------------

Space Complexity: O(1)

At most 128 ASCII character mappings — effectively constant.

--------------------------------------------------

Pattern Used:
Hashing / Bidirectional Character Mapping

Key Learning:

1. Isomorphic problems require TWO maps — one for each direction.
2. A single map allows multiple source chars to collide at one target.
3. This exact bidirectional pattern also solves Word Pattern (290).
4. Always check BEFORE setting the mapping to catch conflicts early.
*/



class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // s → t mapping
        unordered_map<char, char> mp1;

        // t → s mapping
        unordered_map<char, char> mp2;

        for(int i = 0; i < s.size(); i++)
        {
            // Check if s[i] already maps to a different t[i]
            if(mp1.count(s[i]) && mp1[s[i]] != t[i])
            {
                return false;
            }

            // Check if t[i] already maps back to a different s[i]
            if(mp2.count(t[i]) && mp2[t[i]] != s[i])
            {
                return false;
            }

            // Establish bidirectional mapping
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }

        return true;
    }
};
