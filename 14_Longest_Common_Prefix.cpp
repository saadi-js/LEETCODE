/*
Problem 14. Longest Common Prefix

Problem Statement:
Given an array of strings strs, return the longest common prefix
among all strings.

If there is no common prefix, return an empty string "".

Intuition:
Instead of comparing all strings pairwise, we use a clever observation:
After sorting, the strings that differ the most will be at the ends.

So:
- First string (lexicographically smallest)
- Last string (lexicographically largest)

Only these two determine the global common prefix.

Key Idea:
Sort the array and compare only:
- strs[0]
- strs[n-1]

Their common prefix is the answer for the whole array.

Approach:
1. Sort the vector of strings.
2. Take first and last string.
3. Compare characters one by one.
4. Stop when mismatch occurs.
5. Build prefix from matching characters.

Example:

Input:
["flower", "flow", "flight"]

Sorted:
["flight", "flow", "flower"]

Compare:
flight
flower

Common prefix = "fl"

Why This Works:
Sorting groups strings lexicographically.
The first and last strings are the most different,
so their common prefix is the minimum prefix shared by all.

Time Complexity: O(n log n + m)
Space Complexity: O(1) extra (ignoring sorting)

Pattern Used:
Sorting + Boundary Comparison

Key Learning:
When a problem involves "common prefix among many strings",
sorting can reduce it to comparing only two extremes.
*/



class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {

        // Sort strings lexicographically
        sort(strs.begin(), strs.end());

        // Take first string (smallest lexicographically)
        string first = strs.front();

        // Take last string (largest lexicographically)
        string last = strs.back();

        // Result string for common prefix
        string result = "";

        // Compare characters of first and last strings
        for(int i = 0; i < min(first.size(), last.size()); i++)
        {
            // If mismatch found, stop comparison
            if(first[i] != last[i])
            {
                break;
            }
            else
            {
                // Add matching character to result
                result += first[i];
            }
        }

        // Return longest common prefix
        return result;
    }
};
