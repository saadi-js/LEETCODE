/*
Problem 128. Longest Consecutive Sequence

Problem Statement:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must design an algorithm that runs in O(n) time.

Intuition:
Sorting would naturally group consecutive numbers, but that costs O(n log n).

Instead, we use a HashSet to allow O(1) lookups and simulate sequence expansion.

Key Idea:
Only start counting a sequence from its "beginning".

A number x is the start of a sequence if:
(x - 1) is NOT present in the set.

From such a starting point, we expand forward (x+1, x+2, ...) as long as numbers exist.

This avoids repeated work and ensures each sequence is processed once.

Approach:
1. Insert all elements into an unordered_set for O(1) lookup.
2. Initialize longest = 0.
3. For each element x in the set:
   a. Check if x is the start of a sequence (x-1 not in set).
   b. If yes:
      - Start counting length from x
      - Expand using x+1, x+2, ...
   c. Update longest length.
4. Return longest.

Example:
nums = [100,4,200,1,3,2]

Set = {1,2,3,4,100,200}

Start points:
- 1 → sequence: 1,2,3,4 → length = 4
- 100 → sequence: 100 → length = 1
- 200 → sequence: 200 → length = 1

Answer = 4

Why This Works:
We avoid redundant traversals by ensuring we only expand from sequence starting points.

Each number is visited at most twice (once in loop, once in expansion), giving O(n).

Time Complexity: O(n)
Space Complexity: O(n)

Pattern Used:
HashSet + Sequence Expansion (Start Point Optimization)

Key Learning:
Whenever a problem asks for consecutive sequences:
→ Use HashSet
→ Only start from sequence beginnings (x-1 not present)
*/



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Edge case: empty array
        if(nums.empty()) {
            return 0;
        }

        // Insert all numbers into a set for O(1) lookup
        unordered_set<int> st(nums.begin(), nums.end());

        // Stores longest consecutive sequence length
        int longest = 0;

        // Iterate through each unique element
        for(int x : st)
        {
            // Check if x is the start of a sequence
            if(st.find(x - 1) == st.end())
            {
                // Start expanding from x
                int current = x;

                // Length of current sequence
                int length = 1;

                // Expand forward while consecutive numbers exist
                while(st.find(current + 1) != st.end())
                {
                    current++;      // move to next number
                    length++;       // increase sequence length
                }

                // Update maximum sequence length
                longest = max(longest, length);
            }
        }

        // Return longest consecutive sequence length
        return longest;
    }
};
