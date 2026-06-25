/*
Problem 1431. Kids With the Greatest Number of Candies

Problem Statement:
There are n kids with candies. You are given an integer array candies,
where candies[i] represents the number of candies the ith kid has,
and an integer k (extra candies to give).

Return a boolean array result where result[i] is true if the ith kid
can have the greatest number of candies after receiving k extra candies,
or false otherwise.

Note: Multiple kids can have the greatest number simultaneously.

--------------------------------------------------

Intuition:

For kid i to have the greatest number after receiving k candies,
their total (candies[i] + k) must be >= the current maximum
number of candies any kid has.

So we just need to:
1. Find the current maximum
2. Check each kid against that threshold

--------------------------------------------------

Key Idea:

Threshold = max(candies)

For each kid i:
   candies[i] + k >= maxCandies → true
   otherwise → false

--------------------------------------------------

Approach:

1. Find maxCandies = maximum value in candies array.
2. For each kid:
   - If candies[i] + k >= maxCandies → push true
   - Else → push false
3. Return result array.

--------------------------------------------------

Example:

candies = [2, 3, 5, 1, 3]
k = 3

maxCandies = 5

Kid 0: 2 + 3 = 5 >= 5 → true
Kid 1: 3 + 3 = 6 >= 5 → true
Kid 2: 5 + 3 = 8 >= 5 → true
Kid 3: 1 + 3 = 4 >= 5 → false
Kid 4: 3 + 3 = 6 >= 5 → true

Output: [true, true, true, false, true]

--------------------------------------------------

Why This Works:

We only need to beat or tie the current maximum, since
multiple kids can share the greatest number simultaneously.
Finding the max first reduces the problem to a single
comparison per kid.

--------------------------------------------------

Time Complexity: O(n)

One pass to find max, one pass to build result.

--------------------------------------------------

Space Complexity: O(1)

Excluding the output array.

--------------------------------------------------

Pattern Used:
Array / Single Pass with Precomputed Maximum

Key Learning:

1. When a condition depends on a global property (like max),
   compute it first in a separate pass.
2. The >= comparison handles the tie case naturally — multiple
   kids can share the greatest number simultaneously.
3. This two-pass pattern (compute global info → use it) appears
   in many array problems like Product of Array Except Self
   and Replace Elements with Greatest Element on Right Side.
*/



class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int k) {

        // Result array
        vector<bool> ans;

        // Step 1: Find current maximum candies any kid has
        int maxCandies = 0;

        for(int x : candies)
        {
            maxCandies = max(maxCandies, x);
        }

        // Step 2: Check each kid against the threshold
        for(int i = 0; i < candies.size(); i++)
        {
            // If kid i can reach or exceed current max after extra k candies
            if(candies[i] + k >= maxCandies)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;
    }
};
