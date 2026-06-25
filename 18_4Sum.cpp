/*
Problem 18. 4Sum

Problem Statement:
Given an array nums of n integers and an integer target, return all
unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
- a, b, c, d are distinct indices
- nums[a] + nums[b] + nums[c] + nums[d] == target

The solution must not contain duplicate quadruplets.

--------------------------------------------------

Intuition:

This is a direct extension of 3Sum, which itself extends 2Sum.

Pattern:
- 2Sum   → HashMap or Two Pointers         O(n)
- 3Sum   → Fix one + Two Pointers          O(n²)
- 4Sum   → Fix two + Two Pointers          O(n³)

Each additional element adds one more fixed loop and one more
dimension of duplicate handling.

--------------------------------------------------

Key Idea:

Sort the array first.
Fix the first two elements with nested loops (i and j).
For the remaining two elements, use two pointers (left, right).

Duplicate handling at each level:
- Skip i if nums[i] == nums[i-1]
- Skip j if nums[j] == nums[j-1] (but only when j > i+1)
- After finding a valid quadruplet, skip duplicate left and right

Use long long for the sum to prevent integer overflow.

--------------------------------------------------

Approach:

1. Sort nums.
2. Loop i from 0 to n-1:
   - Skip duplicate i values
   - Loop j from i+1 to n-1:
       - Skip duplicate j values
       - Set left = j+1, right = n-1
       - While left < right:
           - Compute sum = nums[i] + nums[j] + nums[left] + nums[right]
           - If sum == target: store, advance both, skip duplicates
           - If sum < target: left++
           - If sum > target: right--
3. Return all valid quadruplets.

--------------------------------------------------

Example:

nums = [1,0,-1,0,-2,2], target = 0

Sorted: [-2,-1,0,0,1,2]

Valid quadruplets:
[-2,-1,1,2]
[-2,0,0,2]
[-1,0,0,1]

Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

--------------------------------------------------

Why long long for sum?

nums[i] can be up to 10⁹.
Four such values summed: 4 × 10⁹ which overflows int (max ~2.1 × 10⁹).
Casting to long long before addition prevents this.

--------------------------------------------------

Time Complexity: O(n³)

Two nested loops O(n²) + two-pointer inner scan O(n).

--------------------------------------------------

Space Complexity: O(1)

Excluding the output array. Sorting is in-place.

--------------------------------------------------

Pattern Used:
Two Pointers + Sorting + Duplicate Skipping (K-Sum Extension)

Key Learning:

1. K-Sum problems follow a pattern: fix k-2 elements with loops,
   solve remaining 2Sum with two pointers.
2. Always sort first to enable two pointers and easy duplicate skipping.
3. Use long long when summing multiple large integers.
4. Duplicate skipping conditions differ slightly between outer
   loops (i > 0) and inner loops (j > i+1) — be careful.
5. This pattern generalizes: 5Sum would add one more fixed loop.
*/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // Sort to enable two pointers and duplicate skipping
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        int n = nums.size();

        // Fix first element
        for(int i = 0; i < n; i++)
        {
            // Skip duplicate values for i
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            // Fix second element
            for(int j = i + 1; j < n; j++)
            {
                // Skip duplicate values for j
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Two pointers for remaining two elements
                int left = j + 1;
                int right = n - 1;

                while(left < right)
                {
                    // Use long long to prevent overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if(sum == target)
                    {
                        // Valid quadruplet found
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        right--;

                        // Skip duplicate left values
                        while(left < right && nums[left] == nums[left - 1])
                        {
                            left++;
                        }

                        // Skip duplicate right values
                        while(left < right && nums[right] == nums[right + 1])
                        {
                            right--;
                        }
                    }
                    else if(sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
