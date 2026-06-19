/*
Problem 78. Subsets

Problem Statement:
Given an integer array nums of unique elements, return all possible subsets
(the power set).

The solution set must not contain duplicate subsets.

Intuition:
For every element in the array, we have exactly two choices:
1. Include it in the current subset
2. Exclude it from the current subset

This naturally forms a binary decision tree where each level represents a decision
for one element.

We explore all paths of this decision tree using recursion + backtracking.

Key Idea:
At index i, recursively decide:
- Take nums[i]
- Don't take nums[i]

Each leaf node of the recursion tree represents a complete subset.

Approach:
1. Start from index 0 with an empty subset.
2. At each index:
   a. Include current element and move forward.
   b. Backtrack (remove element).
   c. Exclude current element and move forward.
3. When index reaches nums.size(), store the subset in result.
4. Continue until all possibilities are explored.

Example:
nums = [1,2,3]

Decision Tree:

                []
           /            \
        [1]              []
      /     \          /     \
   [1,2]   [1]      [2]      []
   /  \     / \      / \      / \
[1,2,3]...

Final subsets:
[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]

Why This Works:
Each element has exactly 2 states: present or absent.
So total subsets = 2^n.

Backtracking ensures that after exploring one branch,
we restore state before exploring the next branch.

Time Complexity: O(2^n)
Space Complexity: O(n) recursion stack (excluding output)

Pattern Used:
Backtracking (Decision Tree / Inclusion-Exclusion)

Key Learning:
Whenever each element has 2 choices (take/not take),
think recursion + backtracking → power set generation.
*/



class Solution {
public:

    // Recursive function to generate all subsets
    void getsubset(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& result)
    {
        // Base case: all elements processed
        if(i == nums.size())
        {
            // Store current subset
            result.push_back(ans);
            return;
        }

        // Include current element in subset
        ans.push_back(nums[i]);

        // Recurse with inclusion
        getsubset(nums, ans, i+1, result);

        // Backtrack: remove last element before exploring next path
        ans.pop_back();

        // Exclude current element and move forward
        getsubset(nums, ans, i+1, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        // Stores all subsets
        vector<vector<int>> result;

        // Temporary subset being built
        vector<int> ans;

        // Start recursion from index 0
        getsubset(nums, ans, 0, result);

        return result;
    }
};
