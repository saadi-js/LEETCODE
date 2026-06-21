/*
Problem 451. Sort Characters By Frequency

Problem Statement:
Given a string s, sort it in decreasing order based on the frequency
of characters. Characters with higher frequency should appear first.

Intuition:
We need to group characters by how often they appear, then reconstruct
the string starting from highest frequency to lowest.

Instead of sorting characters directly (O(n log n)), we use bucket sort.

Key Idea:
1. Count frequency of each character
2. Use bucket array where index = frequency
3. Place characters into corresponding frequency buckets
4. Build result from highest frequency to lowest

Approach:
1. Create frequency map (char → count)
2. Find max frequency
3. Create buckets: vector<vector<char>> where index = frequency
4. Place each character into buckets[frequency]
5. Iterate from max frequency → 1
6. Append characters freq times into result

Example:

Input: "tree"

Frequencies:
t → 1
r → 1
e → 2

Buckets:
1 → [t, r]
2 → [e]

Build result:
freq 2 → "ee"
freq 1 → "t", "r"

Output: "eetr" or "eert"

Why This Works:
Grouping by frequency removes need for sorting,
and bucket traversal ensures correct ordering.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern Used:
Bucket Sort / Frequency Counting

Key Learning:
When sorting by frequency, bucket sort is often better than heap or sorting.
*/



class Solution {
public:

    string frequencySort(string s) {

        // Frequency map for characters
        unordered_map<char, int> mp;

        // Count frequency of each character
        for(char c : s)
        {
            mp[c]++;
        }

        // Find maximum frequency
        int maxfreq = 0;
        for(auto &p : mp)
        {
            maxfreq = max(maxfreq, p.second);
        }

        // Buckets where index = frequency
        vector<vector<char>> buckets(maxfreq + 1);

        // Place characters into corresponding frequency bucket
        for(auto &p : mp)
        {
            buckets[p.second].push_back(p.first);
        }

        // Result string
        string result;

        // Traverse buckets from high frequency to low
        for(int freq = maxfreq; freq >= 1; freq--)
        {
            for(char c : buckets[freq])
            {
                // Append character 'freq' times
                result.append(freq, c);
            }
        }

        return result;
    }
};
