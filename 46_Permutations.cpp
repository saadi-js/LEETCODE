/*
Problem 46. Permutations

Problem Statement:
Given an array nums of distinct integers, return all possible permutations.

Intuition:
A permutation is an arrangement of elements where order matters.

At each index, we try placing every possible remaining element in that position.

We build permutations by swapping elements in-place, fixing one position at a time.

Key Idea:
Use Backtracking with Swapping.

At index idx:
- Fix one element at position idx by swapping it with every possible index i ≥ idx
- Recurse for next index idx + 1
- Backtrack by swapping back to restore original state

Approach:
1. Start from index 0.
2. For each index, iterate over all possible elements that can be placed there.
3. Swap nums[idx] with nums[i].
4. Recurse for next index.
5. Swap back to restore array (backtracking).
6. When idx reaches nums.size(), store current permutation.

Example:
nums = [1,2,3]

Step tree:

idx = 0:
- swap(0,0) → [1,2,3]
- swap(0,1) → [2,1,3]
- swap(0,2) → [3,2,1]

Each branch generates all permutations recursively.

Why This Works:
Each recursive level fixes one position in the permutation.

Swapping ensures:
- No extra space used for visited array
- All possible arrangements are explored systematically

Time Complexity: O(n! * n)
Space Complexity: O(n) recursion stack

Pattern Used:
Backtracking (In-place Swapping / Permutation Generation)

Key Learning:
Whenever order matters and we need all arrangements:
→ Think permutations
→ Use swap-based backtracking or visited array approach
*/



class Solution {
public:

    // Recursive function to generate permutations
    void getperms(vector<int>& nums, int idx, vector<vector<int>> &ans)
    {
        // Base case: a full permutation is formed
        if(idx == nums.size())
        {
            // Store current permutation
            ans.push_back(nums);  // FIX: remove extra braces
            return;
        }

        // Try placing every element at position idx
        for(int i = idx; i < nums.size(); i++)
        {
            // Swap current index with i
            swap(nums[idx], nums[i]);

            // Recurse for next index
            getperms(nums, idx + 1, ans);

            // Backtrack (restore original array)
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        // Stores all permutations
        vector<vector<int>> ans;

        // Start recursion from index 0
        getperms(nums, 0, ans);

        return ans;
    }
};
