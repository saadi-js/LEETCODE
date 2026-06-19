/*
Problem 242. Valid Anagram

Problem Statement:
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An anagram is a word or phrase formed by rearranging the letters of another,
using all original letters exactly once.

Intuition:
Two strings are anagrams if they have exactly the same character frequencies.

So instead of comparing arrangements, we compare counts of each character.

Key Idea:
Use a frequency map to count characters in one string, then subtract using the other.

If at any point a mismatch occurs (missing character or negative count),
the strings are not anagrams.

Approach:
1. If lengths differ → return false immediately.
2. Count frequency of each character in string s.
3. Traverse string t:
   - If character not present or count is 0 → return false
   - Otherwise decrement its count
4. If all characters match correctly → return true.

Example:
s = "anagram"
t = "nagaram"

Frequency of s:
a:3, n:1, g:1, r:1, m:1

Processing t reduces all counts to zero → valid anagram.

Why This Works:
Anagrams preserve character frequency exactly.
So comparing frequency distributions guarantees correctness.

Time Complexity: O(n)
Space Complexity: O(1) (bounded 26 letters if lowercase English)

Pattern Used:
Hashing / Frequency Count

Key Learning:
Whenever order does not matter but character composition does:
→ Use frequency map or counting array
*/



class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths differ, cannot be anagram
        if(s.size() != t.size()) return false;

        // Frequency map for characters in string s
        unordered_map<int, int> mp;

        // Count frequency of each character in s
        for(char c : s)
        {
            mp[c]++;
        }

        // Match frequencies using string t
        for(char c : t)
        {
            // If character not found or already exhausted
            if(mp.find(c) == mp.end() || mp[c] == 0)
            {
                return false;
            }

            // Decrease frequency
            mp[c]--;
        }

        // All characters matched correctly
        return true;
    }
};
