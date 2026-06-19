/*
Problem 567. Permutation in String

Problem Statement:
Given two strings s1 and s2, return true if s2 contains a permutation of s1,
or false otherwise.

In other words:
Check if any substring of s2 is an anagram of s1.

Intuition:
A permutation of s1 means:
- same characters
- same frequency distribution

So instead of generating permutations (which is factorial complexity),
we check all substrings of length |s1| in s2 using a sliding window.

Key Idea:
Maintain a fixed-size sliding window over s2 and compare:
- frequency of s1
- frequency of current window in s2

If both frequency arrays match → valid permutation exists.

Approach:
1. Build frequency array freq1 for s1.
2. Use sliding window of size = s1.length().
3. Maintain freq2 for current window in s2.
4. For each index i in s2:
   a. Add current character to freq2
   b. If window size exceeds s1 size:
        remove leftmost character
   c. Compare freq1 and freq2
   d. If equal → return true
5. If no match found → return false.

Example:
s1 = "ab"
s2 = "eidbaooo"

Windows in s2:
"ei" → no
"id" → no
"db" → yes (permutation of "ab")

Why This Works:
All permutations of s1 share identical frequency patterns.
Sliding window ensures we only check valid substrings efficiently.

Time Complexity: O(n * 26) ≈ O(n)
Space Complexity: O(1)

Pattern Used:
Sliding Window (Fixed Size) + Frequency Matching

Key Learning:
Whenever problem says "permutation in string":
→ Think fixed-size sliding window + frequency comparison
*/



class Solution {
public:

    // Helper function to compare two frequency arrays
    bool issame(vector<int> &a, vector<int> &b)
    {
        // Compare all 26 lowercase letters
        for(int i = 0; i < 26; i++)
        {
            if(a[i] != b[i])
            {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {

        // Frequency array for s1
        vector<int> freq1(26, 0);

        // Frequency array for current window in s2
        vector<int> freq2(26, 0);

        // Build frequency of s1
        for(char c : s1)
        {
            freq1[c - 'a']++;
        }

        // Fixed window size equals length of s1
        int windowsize = s1.size();

        // Sliding window over s2
        for(int i = 0; i < s2.size(); i++)
        {
            // Add current character to window
            freq2[s2[i] - 'a']++;

            // Remove leftmost character if window exceeds size
            if(i >= windowsize)
            {
                freq2[s2[i - windowsize] - 'a']--;
            }

            // Compare frequency maps
            if(issame(freq1, freq2))
            {
                return true;
            }
        }

        return false;
    }
};
