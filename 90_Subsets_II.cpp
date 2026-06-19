/*
Problem 90. Subsets II

Problem Statement:
Given an integer array nums that may contain duplicates, return all possible subsets
(the power set). The solution set must not contain duplicate subsets.

Intuition:
This is an extension of the standard Subsets problem, but duplicates in the input
can lead to duplicate subsets in the output.

To prevent duplicates, we must ensure that identical elements at the same recursion
level are not processed multiple times.

Key Idea:
1. Sort the array so duplicates become adjacent.
2. Use backtracking with a loop-based recursion.
3. At each recursion level, skip duplicates using:
   if(i > start && nums[i] == nums[i-1]) continue;

This ensures that duplicate values are only used once per level.

Approach:
1. Sort the input array.
2. Start backtracking from index 0.
3. At each recursive call:
   - Add current subset to result.
   - Loop from 'start' to end of array.
   - Skip duplicates at same depth level.
   - Include current element.
   - Recurse with next index.
   - Backtrack.
4. Continue until all subsets are generated.

Example:
nums = [1,2,2]

Sorted: [1,2,2]

Subsets:
[]
[1]
[1,2]
[1,2,2]
[2]
[2,2]
[1,2(second path avoided duplicate)]

Why This Works:
Sorting groups duplicates together, allowing us to detect repeated values easily.

The condition:
i > start && nums[i] == nums[i-1]
ensures that within the same recursion depth, we do not pick the same value twice,
preventing duplicate subsets.

Time Complexity: O(2^n)
Space Complexity: O(n) recursion stack (excluding output)

Pattern Used:
Backtracking + Sorting + Duplicate Pruning

Key Learning:
Whenever duplicates exist in input for combinatorial problems:
→ Sort first
→ Skip duplicates at the same recursion level
*/



class Solution {
public:

    // Recursive function to generate subsets without duplicates
    void solve(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& result)
    {
        // Add current subset to result
        result.push_back(temp);

        // Explore all options starting from 'start'
        for(int i = start; i < nums.size(); i++)
        {
            // Skip duplicates at the same recursion depth
            if(i > start && nums[i] == nums[i-1])
            {
                continue;
            }

            // Include current element in subset
            temp.push_back(nums[i]);

            // Recurse with next index
            solve(nums, i + 1, temp, result);

            // Backtrack: remove last element
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Stores all unique subsets
        vector<vector<int>> result;

        // Temporary subset being built
        vector<int> temp;

        // Step 1: Sort array to group duplicates together
        sort(nums.begin(), nums.end());

        // Step 2: Start backtracking
        solve(nums, 0, temp, result);

        return result;
    }
};
