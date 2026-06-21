/*
Problem 3866. First Unique Even Element

Problem Statement:
Given an integer array nums, return the first element that is:
- Even
- Appears exactly once in the array

If no such element exists, return -1.

--------------------------------------------------

Intuition:

We need to find elements satisfying two conditions simultaneously:
1. The element must be even
2. The element must appear exactly once (unique)

A brute force approach would check every even element against the
rest of the array for duplicates, resulting in O(n²).

We can reduce this to O(n) using a frequency map.

--------------------------------------------------

Key Idea:

Two-pass approach:

Pass 1: Build a frequency map counting occurrences of even numbers only.
         We ignore odd numbers entirely since they can never be the answer.

Pass 2: Traverse nums in original order.
         Return the first element whose frequency in the map is exactly 1.

The original order traversal in Pass 2 is critical —
it preserves the "first" requirement.

--------------------------------------------------

Approach:

1. Traverse nums:
   - If element is even, increment its count in the map.
2. Traverse nums again in order:
   - If element exists in map AND its count == 1, return it.
3. If no unique even element found, return -1.

--------------------------------------------------

Example:

nums = [2, 4, 3, 2, 6, 4]

Pass 1 (even elements only):
2 → 2
4 → 2
6 → 1

Pass 2 (original order):
2 → count 2 → skip
4 → count 2 → skip
3 → not in map → skip
2 → count 2 → skip
6 → count 1 → return 6

Output: 6

--------------------------------------------------

Why This Works:

By filtering only even elements in the frequency map,
we avoid polluting the map with odd numbers.

The second pass in original order ensures we return the
leftmost qualifying element, satisfying the "first" condition.

Checking mp[x] == 1 handles both the uniqueness and the
implicit even-filter (only even elements were inserted into mp).

--------------------------------------------------

Time Complexity: O(n)

Two linear passes through the array.

--------------------------------------------------

Space Complexity: O(n)

HashMap stores at most n/2 even elements in the worst case.

--------------------------------------------------

Pattern Used:
Hashing / Two-Pass Frequency Count

Key Learning:

1. When multiple conditions must be satisfied, filter during
   the counting phase to keep the map clean.
2. Always traverse in original order when "first occurrence"
   is required — do not iterate over the map directly.
3. Checking map membership implicitly handles the even filter
   in the second pass since odd numbers were never inserted.
*/



class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {

        // Step 1: Count frequency of even elements only
        unordered_map<int, int> mp;

        for(int x : nums)
        {
            // Only track even numbers
            if(x % 2 == 0)
            {
                mp[x]++;
            }
        }

        // Step 2: Find first element with frequency exactly 1
        // Traverse in original order to preserve "first" requirement
        for(int x : nums)
        {
            // mp[x] == 1 means x is even (only evens in map) AND unique
            if(mp[x] == 1)
            {
                return x;
            }
        }

        // No unique even element found
        return -1;
    }
};
