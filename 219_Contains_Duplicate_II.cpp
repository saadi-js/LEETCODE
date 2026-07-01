/*
Problem 219. Contains Duplicate II

Problem Statement:
Given an integer array nums and an integer k, return true if there are
two distinct indices i and j in the array such that:
- nums[i] == nums[j]
- |i - j| <= k

--------------------------------------------------

Intuition:

We need to find duplicate values that are within k positions of each other.

A HashMap storing value → most recent index gives O(1) lookup.
When we see a value again, we check if the distance to its last
occurrence is within k.

--------------------------------------------------

Key Idea:

For each element at index i:
- If it exists in the map AND i - map[nums[i]] <= k → return true
- Update map[nums[i]] = i (always store most recent index)

Storing the most recent index is correct because:
if the most recent occurrence is not within k, no earlier one will be.

--------------------------------------------------

Approach:

1. Initialize empty HashMap.
2. For each index i:
   - If nums[i] in map AND i - map[nums[i]] <= k → return true
   - Update map[nums[i]] = i
3. Return false.

--------------------------------------------------

Example:

nums = [1,2,3,1], k = 3

i=0: 1 not in map → store 1→0
i=1: 2 not in map → store 2→1
i=2: 3 not in map → store 3→2
i=3: 1 in map, 3-0=3 <= 3 → return true

--------------------------------------------------

Example 2:

nums = [1,2,3,1,2,3], k = 2

i=3: 1 in map, 3-0=3 > 2 → update 1→3
i=4: 2 in map, 4-1=3 > 2 → update 2→4
i=5: 3 in map, 5-2=3 > 2 → update 3→5

return false

--------------------------------------------------

Why Always Update the Index?

If we find a duplicate that is too far away, we update to the current
index. This is optimal because any future occurrence of the same value
will be closer to the current index than to the old one.

--------------------------------------------------

Time Complexity: O(n)

Single pass with O(1) HashMap operations.

--------------------------------------------------

Space Complexity: O(n)

HashMap stores at most n entries.

--------------------------------------------------

Pattern Used:
Hashing / Index Tracking

Key Learning:

1. HashMap storing value → latest index is the standard pattern
   for "find duplicate within distance k" problems.
2. Always update the stored index even when the distance check fails —
   this ensures future lookups use the closest previous occurrence.
3. This extends naturally to sliding window approaches where a
   HashSet of size k+1 is maintained instead.
*/



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // Maps value to its most recent index
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++)
        {
            // If value seen before, check distance
            if(mp.find(nums[i]) != mp.end())
            {
                if(i - mp[nums[i]] <= k)
                {
                    return true;
                }
            }

            // Always update to most recent index
            mp[nums[i]] = i;
        }

        return false;
    }
};
