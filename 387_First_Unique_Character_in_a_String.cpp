/*
Problem 387. First Unique Character in a String

Problem Statement:
Given a string s, find the first non-repeating character in it
and return its index. If it does not exist, return -1.

--------------------------------------------------

Intuition:

A brute force approach would compare every character with every
other character in the string to check for repetition.

This takes O(n²) time.

Since we only deal with lowercase English letters (26 characters),
we can use a fixed-size frequency array to count all occurrences
in a single pass, then find the first character with count 1.

--------------------------------------------------

Key Idea:

Two-pass approach using a frequency array of size 26:

Pass 1: Count the frequency of every character in the string.
Pass 2: Scan the string left to right and return the index
        of the first character whose frequency is exactly 1.

The frequency array uses the character's offset from 'a' as the index:
    index = char - 'a'

--------------------------------------------------

Approach:

1. Create freq[26] initialized to 0.
2. Traverse string s:
   - Increment freq[s[i] - 'a'] for each character.
3. Traverse string s again from left to right:
   - If freq[s[i] - 'a'] == 1 → return index i.
4. If no unique character found → return -1.

--------------------------------------------------

Example:

s = "leetcode"

Pass 1 (frequency count):
l → 1
e → 3
t → 1
c → 1
o → 1
d → 1

Pass 2 (left to right scan):
l → freq 1 → return 0

Output: 0

--------------------------------------------------

Counter Example:

s = "aabb"

Frequency:
a → 2
b → 2

Pass 2:
a → 2, skip
a → 2, skip
b → 2, skip
b → 2, skip

Output: -1

--------------------------------------------------

Why This Works:

The frequency array captures all repetitions in O(n).

The second left-to-right pass ensures we return the
leftmost non-repeating character, satisfying the "first" requirement.

Using a fixed array of size 26 instead of a HashMap gives
slightly better constant factors since the key space is known.

--------------------------------------------------

Time Complexity: O(n)

Two linear passes through the string.

--------------------------------------------------

Space Complexity: O(1)

Fixed array of size 26 regardless of input length.

--------------------------------------------------

Pattern Used:
Frequency Array / Two-Pass Count

Key Learning:

1. When the character set is fixed and small (a-z = 26),
   prefer a frequency array over a HashMap for simplicity and speed.
2. Two-pass approach: first count globally, then scan for condition.
3. This exact pattern also appears in Valid Anagram and
   Permutation in String.
4. Always scan in original order when "first occurrence" matters.
*/



class Solution {
public:
    int firstUniqChar(string s) {

        // Frequency array for 26 lowercase English letters
        vector<int> freq(26, 0);

        // Pass 1: Count frequency of each character
        for(char x : s)
        {
            freq[x - 'a']++;
        }

        // Pass 2: Find first character with frequency exactly 1
        for(int i = 0; i < s.size(); i++)
        {
            // If this character appears only once, return its index
            if(freq[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        // No unique character found
        return -1;
    }
};
