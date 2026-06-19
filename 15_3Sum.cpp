/*
Problem 15. 3Sum

Problem Statement:
Given an integer array nums, return all unique triplets [nums[i], nums[j], nums[k]]
such that:
- i != j, i != k, j != k
- nums[i] + nums[j] + nums[k] == 0

The solution must not contain duplicate triplets.

Intuition:
This is an extension of the Two Sum problem.

Instead of fixing one number and using hashing for the rest, we sort the array
and use a two-pointer approach to efficiently find pairs that complete the sum.

Sorting helps in:
1. Efficient two-pointer search
2. Easy duplicate handling

Key Idea:
Fix one element nums[i], then solve a 2Sum problem on the remaining subarray
using two pointers (j, k).

To avoid duplicates:
- Skip same value for i
- Skip duplicate values for j after finding a valid triplet

Approach:
1. Sort the array.
2. Iterate i from 0 to n-1:
   a. Skip duplicates for i.
   b. Set j = i+1, k = n-1.
3. While j < k:
   a. Compute sum = nums[i] + nums[j] + nums[k]
   b. If sum > 0 → decrease k
   c. If sum < 0 → increase j
   d. If sum == 0 → store result
      - move both pointers
      - skip duplicate values for j
4. Return all unique triplets.

Example:
nums = [-1,0,1,2,-1,-4]

Sorted:
[-4,-1,-1,0,1,2]

Valid triplets:
[-1,-1,2]
[-1,0,1]

Why This Works:
Sorting allows us to convert the 3Sum problem into a controlled 2Sum search.
Two pointers efficiently explore all valid pairs without recomputation.

Time Complexity: O(n²)
Space Complexity: O(1) (excluding output)

Pattern Used:
Two Pointers + Sorting + Duplicate Skipping

Key Learning:
Whenever you see "find triplets with sum condition":
→ Sort + fix one element + reduce to Two Sum with two pointers
*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Sort array to enable two-pointer technique and duplicate handling
        sort(nums.begin(), nums.end());

        // Stores final result of triplets
        vector<vector<int>> ans;

        // Fix first element of triplet
        for(int i = 0; i < nums.size(); i++)
        {
            // Skip duplicate values for i to avoid repeated triplets
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // Two pointers for remaining part
            int j = i + 1;
            int k = nums.size() - 1;

            // Search for pairs that complete sum to zero
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                // Sum too large → reduce right pointer
                if(sum > 0)
                {
                    k--;
                }

                // Sum too small → increase left pointer
                else if(sum < 0)
                {
                    j++;
                }

                // Valid triplet found
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // Move both pointers inward
                    j++;
                    k--;

                    // Skip duplicates for j pointer
                    while(j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                }
            }
        }

        return ans;
    }
};
