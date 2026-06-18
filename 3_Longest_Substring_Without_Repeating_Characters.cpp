/*
Problem 3. Longest Substring Without Repeating Characters

Problem Statement:

Given a string s, find the length of the longest substring without repeating characters.

A substring is a contiguous sequence of characters.

--------------------------------------------------

Intuition:

A brute force solution would:
- Generate all substrings
- Check if each has unique characters

This leads to O(n³) or O(n²) depending on implementation.

We optimize using Sliding Window + Hash Map.

--------------------------------------------------

Key Idea:

We maintain a window [left, right] such that:
- All characters inside the window are unique

We expand the window using 'right'.
If a duplicate appears, we shrink from 'left'.

--------------------------------------------------

Approach:

1. Use two pointers:
   - left → start of window
   - right → end of window

2. Use a frequency map to track characters inside the window.

3. Expand window by moving right pointer:
   - Increase frequency of s[right]

4. If a character appears more than once:
   - Shrink window from left until it becomes valid again

5. At each step:
   - Update maximum window size

--------------------------------------------------

Example:

s = "abcabcbb"

Window expansion:

abc → valid → length 3
abca → duplicate a → shrink
bca → valid → length 3
cab → valid → length 3

Answer = 3

--------------------------------------------------

Why This Works:

We ensure that:
- Window always contains unique characters
- Each character enters and leaves window at most once

So overall complexity is linear.

--------------------------------------------------

Time Complexity: O(n)

Each character is processed at most twice
(one by right pointer, one by left pointer).

--------------------------------------------------

Space Complexity: O(min(n, charset))

Hash map stores character frequencies.

--------------------------------------------------

Pattern Used:
Sliding Window + Frequency Map

Key Learning:

1. Use sliding window when dealing with subarrays/substrings.
2. Expand → contract pattern is key for constraint-based windows.
3. Hash map helps track validity of window efficiently.
4. Very important interview pattern for string problems.
*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Frequency map to store character counts in current window
        unordered_map<char, int> freq;

        // Left pointer of sliding window
        int left = 0;

        // Stores maximum length found so far
        int maxLen = 0;

        // Expand window using right pointer
        for(int right = 0; right < s.length(); right++) {

            // Include current character in window
            freq[s[right]]++;

            // If character becomes duplicate, shrink window
            while(freq[s[right]] > 1) {

                // Remove leftmost character from window
                freq[s[left]]--;

                // Move left pointer forward
                left++;
            }

            // Update maximum length of valid window
            maxLen = max(maxLen, right - left + 1);
        }

        // Return longest valid substring length
        return maxLen;
    }
};
