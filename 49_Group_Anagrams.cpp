/*
Problem 49. Group Anagrams

Problem Statement:
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Anagrams are strings that contain the same characters with the same frequency but in different order.

Intuition:
All anagrams, when sorted, produce the same string.

So we can use the sorted version of each string as a "signature key" to group words.

Key Idea:
Use Hash Map where:
key = sorted version of string
value = list of original strings

All anagrams map to the same key.

Approach:
1. Create an unordered_map<string, vector<string>>.
2. For each string:
   a. Copy string into key.
   b. Sort the key.
   c. Push original string into mp[key].
3. Iterate through map and collect all groups.
4. Return result.

Example:
strs = ["eat","tea","tan","ate","nat","bat"]

Step:
"eat" → "aet"
"tea" → "aet"
"ate" → "aet"

"tan" → "ant"
"nat" → "ant"

"bat" → "abt"

Groups:
["eat","tea","ate"]
["tan","nat"]
["bat"]

Why This Works:
Sorting normalizes all anagrams into a common representation.
Hash map groups identical representations together.

Time Complexity: O(n * k log k)
where:
n = number of strings
k = max length of a string (sorting cost)

Space Complexity: O(n * k)

Pattern Used:
Hashing + Canonical Representation (Sorting as Key)

Key Learning:
Whenever grouping based on "rearranged equality":
→ Convert to canonical form (sorted string or frequency signature)
→ Use hash map for grouping
*/



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Map: sorted string → list of anagrams
        unordered_map<string, vector<string>> mp;

        // Process each string
        for(string s : strs)
        {
            // Create key by sorting characters
            string key = s;

            // Sorting gives canonical form of anagrams
            sort(key.begin(), key.end());

            // Group original string under sorted key
            mp[key].push_back(s);
        }

        // Final result
        vector<vector<string>> result;

        // Collect all grouped anagrams
        for(auto &p : mp)
        {
            result.push_back(p.second);
        }

        return result;
    }
};
