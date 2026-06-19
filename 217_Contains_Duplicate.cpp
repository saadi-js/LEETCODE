/*
Problem 217. Contains Duplicate

Problem Statement:
Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.

Intuition:
We need to detect whether an element has already been seen before.

Instead of comparing every pair (which is inefficient), we store previously seen elements
and check membership in constant time.

Key Idea:
Use a Hash-based lookup structure (unordered_map / unordered_set).

For each element:
- If it already exists in the structure → duplicate found
- Otherwise, insert it into the structure

Approach:
1. Traverse the array.
2. Maintain a hash map of seen elements.
3. For each nums[i]:
   a. Check if it already exists in map.
   b. If yes → return true immediately.
   c. If no → store it.
4. If traversal completes → return false.

Example:
nums = [1,2,3,1]

Step-by-step:
1 → store
2 → store
3 → store
1 → already exists → return true

Why This Works:
Hashing provides O(1) average time lookup.
So we efficiently track whether we've seen an element before.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern Used:
Hashing / Frequency Tracking

Key Learning:
Whenever you need to check repetition or uniqueness in an array:
→ Think HashSet / HashMap for constant-time lookup
*/



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // Hash map to store seen elements
        unordered_map<int, int> mp;

        // Traverse the array
        for(int i = 0; i < nums.size(); i++)
        {
            // If element already exists, duplicate found
            if(mp.find(nums[i]) != mp.end())
            {
                return true;
            }

            // Otherwise mark element as seen
            else
            {
                mp[nums[i]] = 1;
            }
        }

        // No duplicates found
        return false;
    }
};
