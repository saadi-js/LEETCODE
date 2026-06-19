/*
Problem 1. Two Sum

Problem Statement:
Given an array of integers nums and an integer target, return indices of the two numbers such that
they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Intuition:
Instead of checking every pair (which is O(n²)), we can use a hash map to remember numbers we have
already seen.

For each number, we check whether its complement (target - current number) has already been seen.

If yes → we found the answer.
If no → store the current number with its index.

Key Idea:
Use Hash Map to store:
value → index

At each step:
- compute complement = target - nums[i]
- check if complement exists in map
- if yes → return stored index and current index
- else → store current element

Approach:
1. Create a hash map mp to store number → index.
2. Traverse the array.
3. For each element:
   a. Compute complement.
   b. Check if complement exists in mp.
   c. If found → return indices.
   d. Otherwise insert current element into map.
4. Guaranteed one solution exists.

Example:
nums = [2,7,11,15], target = 9

Step-by-step:
i=0 → 2
store 2 → mp

i=1 → 7
complement = 9 - 7 = 2 → found in mp → return [0,1]

Why This Works:
We ensure that every number is paired with previously seen numbers only.
This avoids duplicate usage and reduces complexity.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern Used:
Hashing (Complement Search / Two Sum Pattern)

Key Learning:
Whenever you need to find pairs that satisfy a condition:
→ Think complement + HashMap for O(1) lookup instead of nested loops.
*/



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Hash map to store value → index
        unordered_map<int, int> mp;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Compute required complement
            int complement = target - nums[i];

            // Check if complement already exists
            if (mp.find(complement) != mp.end()) {

                // Return indices of complement and current element
                return {mp[complement], i};
            }

            // Store current number with its index
            mp[nums[i]] = i;
        }

        // If no solution found (problem guarantees one exists)
        return {};
    }
};
