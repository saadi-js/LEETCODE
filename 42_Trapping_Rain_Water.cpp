/*
Problem 42. Trapping Rain Water

Problem Statement:
Given an array height representing elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Intuition:
Water at any index depends on:
min(max height on left, max height on right) - current height

A brute force solution recomputes left/right maxima for each index (O(n²)).

Optimized Idea:
We use a two-pointer approach and dynamically maintain:
- leftMax: maximum height seen from the left
- rightMax: maximum height seen from the right

We always process the side with the smaller boundary because:
water level is limited by the smaller of the two sides.

Key Idea:
At each step:
- If leftMax < rightMax → left side is safe to process
- Else → right side is safe to process

We accumulate trapped water incrementally.

Approach:
1. Initialize two pointers: l = 0, r = n-1
2. Maintain:
   - leftMax = 0
   - rightMax = 0
   - ans = 0
3. While l < r:
   a. Update leftMax and rightMax
   b. If leftMax < rightMax:
        - Water trapped at l = leftMax - height[l]
        - Move l++
   c. Else:
        - Water trapped at r = rightMax - height[r]
        - Move r--
4. Return ans.

Example:
height = [0,1,0,2,1,0,1,3,2,1,2,1]

Trapped water = 6

Why This Works:
Water level is always constrained by the smaller boundary.
By always processing the smaller side first, we guarantee that its trapped water
is final and cannot be affected by future updates.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Two Pointers + Prefix/Suffix Maximum Optimization

Key Learning:
Whenever water/area depends on both left and right constraints:
→ Use two pointers with dynamic boundary tracking
*/



class Solution {
public:
    int trap(vector<int>& height) {

        // Stores total trapped water
        int ans = 0;

        // Maximum height seen so far from left
        int leftMax = 0;

        // Maximum height seen so far from right
        int rightMax = 0;

        // Two pointers
        int l = 0;
        int r = height.size() - 1;

        // Process until pointers meet
        while(l < r)
        {
            // Update left and right maximums
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            // Process smaller boundary side
            if(leftMax < rightMax)
            {
                // Water trapped at left index
                ans += leftMax - height[l];

                // Move left pointer inward
                l++;
            }
            else
            {
                // Water trapped at right index
                ans += rightMax - height[r];

                // Move right pointer inward
                r--;
            }
        }

        return ans;
    }
};
