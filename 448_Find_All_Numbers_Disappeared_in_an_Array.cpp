/*
Problem 448. Find All Numbers Disappeared in an Array

Problem Statement:
Given an array nums of size n where nums[i] is in the range [1, n],
some elements appear twice and others appear once.

Return all numbers in the range [1, n] that do not appear in nums.

Intuition:
We use the array itself as a frequency marker.

Instead of using extra space (hash set), we treat each value as an index
and mark that index as "visited" by negating the value.

Key Idea:
If a number x exists in the array:
→ mark index (x - 1) as negative

After marking:
→ any index that remains positive means that number is missing

Approach:
1. Iterate through array:
   - Convert value to index: abs(nums[i]) - 1
   - Mark that index negative (if not already)

2. Second pass:
   - If nums[i] > 0 → (i+1) is missing

Example:

Input:
[4,3,2,7,8,2,3,1]

Marking process:
[-4,-3,-2,-7,8,2,-3,-1]

Unmarked positive index:
8 → missing number

Output:
[5,6]

Why This Works:
We reuse the input array as a hash map by encoding visited states
using sign flipping.

Time Complexity: O(n)
Space Complexity: O(1) extra (excluding output)

Pattern Used:
In-place hashing / Index marking

Key Learning:
When values are in range [1, n], array indices can be used as a hashmap.
*/



class Solution {
public:

    vector<int> findDisappearedNumbers(vector<int>& nums) {

        // Result vector for missing numbers
        vector<int> ans;

        // First pass: mark visited indices
        for(int i = 0; i < nums.size(); i++)
        {
            // Convert value to index
            int index = abs(nums[i]) - 1;

            // If already positive, mark it negative
            if(nums[index] > 0)
            {
                nums[index] = -nums[index];
            }

            // Treat values as indices for marking presence
        }

        // Second pass: collect unmarked indices
        for(int i = 0; i < nums.size(); i++)
        {
            // Positive value means index+1 is missing
            if(nums[i] > 0)
            {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};
