/*
Problem 1207. Unique Number of Occurrences

Problem Statement:
Given an array of integers arr, return true if the number of occurrences
of each value in the array is unique, or false otherwise.

--------------------------------------------------

Intuition:

We need to check two things:

1. How many times does each value appear? → frequency map
2. Are all those frequencies distinct? → check for duplicates in frequencies

A brute force approach would compare every pair of frequencies,
but that is O(k²) where k is number of unique values.

We can do this in O(k) using a hash set.

--------------------------------------------------

Key Idea:

Step 1: Count frequency of each element using a HashMap.
Step 2: Insert each frequency into a HashSet.
        If a frequency already exists in the set → duplicate found → return false.
        Otherwise → insert and continue.
Step 3: If all frequencies inserted without collision → return true.

--------------------------------------------------

Approach:

1. Traverse arr and build frequency map: value → count.
2. Create an empty unordered_set.
3. For each (value, frequency) pair in the map:
   - If frequency already in set → return false
   - Else insert frequency into set
4. Return true

--------------------------------------------------

Example:

arr = [1,2,2,1,1,3]

Frequency map:
1 → 3
2 → 2
3 → 1

Frequencies: {3, 2, 1} → all unique

Output: true

--------------------------------------------------

Counter Example:

arr = [1,2]

Frequency map:
1 → 1
2 → 1

Frequencies: {1, 1} → duplicate found

Output: false

--------------------------------------------------

Why This Works:

HashSet provides O(1) average lookup and insertion.
We exploit the property that a set cannot contain duplicate values,
so trying to insert a repeated frequency immediately reveals the conflict.

--------------------------------------------------

Time Complexity: O(n)

One pass to build frequency map.
One pass over unique values to check frequencies.

--------------------------------------------------

Space Complexity: O(n)

HashMap stores at most n entries.
HashSet stores at most n distinct frequencies.

--------------------------------------------------

Pattern Used:
Hashing / Frequency Count + Uniqueness Verification

Key Learning:

1. Two-step hashing: first count, then verify uniqueness of counts.
2. HashSet's no-duplicate property is a natural duplicate detector.
3. This pattern appears whenever you need to verify that some
   derived property (like frequency) is itself unique.
*/



class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // Step 1: Count frequency of each value
        unordered_map<int, int> freq;

        for(int x : arr)
        {
            freq[x]++;
        }

        // Step 2: Check if all frequencies are unique
        unordered_set<int> seen;

        for(auto &p : freq)
        {
            int f = p.second;

            // If frequency already seen → not unique
            if(seen.count(f))
            {
                return false;
            }

            // Mark this frequency as seen
            seen.insert(f);
        }

        // All frequencies are distinct
        return true;
    }
};
