/*
Problem 424. Longest Repeating Character Replacement

Problem Statement:
Given a string s and an integer k, you can choose any character of the string and
replace it with any other uppercase English character at most k times.

Return the length of the longest substring containing the same letter after performing at most k replacements.

Intuition:
We want the longest substring where we can make all characters identical using at most k changes.

Instead of trying all substrings (O(n²)), we use a sliding window and track:
- frequency of characters in the window
- the most frequent character in the window (maxfreq)

Key Idea:
For any window:
operations needed = window size - max frequency character in that window

If this exceeds k → shrink window.

Approach:
1. Use a frequency array of size 26.
2. Maintain a sliding window [left, right].
3. Track:
   - freq[] → character counts
   - maxfreq → highest frequency in current window
4. Expand right pointer:
   - update frequency
   - update maxfreq
5. If invalid window:
   (window size - maxfreq > k)
   → shrink from left
6. Update maxlen at each step.

Example:
s = "AABABBA", k = 1

Best window: "AABA" → replace B → "AAAA"

Answer = 4

Why This Works:
We always try to maximize the count of a single dominant character in the window.
We only allow at most k "non-dominant" characters.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Sliding Window + Frequency Tracking (Variable Window Size)

Key Learning:
When you need "longest substring with limited modifications":
→ Track max frequency + shrink window when invalid
*/



class Solution {
public:
    int characterReplacement(string s, int k) {

        // Frequency array for A-Z characters
        vector<int> freq(26, 0);

        // Maximum length of valid substring
        int maxlen = 0;

        // Left pointer of sliding window
        int left = 0;

        // Maximum frequency of a single character in current window
        int maxfreq = 0;

        // Expand window using right pointer
        for(int right = 0; right < s.length(); right++)
        {
            // Include current character in window
            freq[s[right] - 'A']++;

            // Update max frequency character in window
            maxfreq = max(maxfreq, freq[s[right] - 'A']);

            // Check if window is valid
            // (window size - maxfreq) = number of replacements needed
            while((right - left + 1) - maxfreq > k)
            {
                // Shrink window from left
                freq[s[left] - 'A']--;
                left++;
            }

            // Update maximum valid window length
            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};
