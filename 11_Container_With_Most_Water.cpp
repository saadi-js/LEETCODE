/*
Problem 11. Container With Most Water

Problem Statement:
Given an array height where each element represents a vertical line on the x-axis,
find two lines that together with the x-axis form a container that holds the maximum amount of water.

Return the maximum water area that can be contained.

Intuition:
We want to maximize area = width × height.

Width depends on distance between two pointers.
Height depends on the shorter of the two lines.

A brute force approach checks all pairs (O(n²)), but we can optimize using two pointers.

Key Idea:
Start with the widest possible container (left = 0, right = n-1).

At each step:
- Compute current area
- Move the pointer pointing to the smaller height inward

Why?
Because width is shrinking, so to potentially get a better area,
we must try to increase height, which only the smaller side can improve.

Approach:
1. Initialize two pointers: left at start, right at end.
2. While left < right:
   a. Compute width = right - left
   b. Compute height = min(height[left], height[right])
   c. Calculate area and update max_area
   d. Move pointer pointing to smaller height
3. Return max_area.

Example:
height = [1,8,6,2,5,4,8,3,7]

Best container:
Between index 1 (8) and index 8 (7)
Area = 7 × 7 = 49

Why This Works:
The limiting factor is always the shorter line.
Moving the taller line inward cannot increase area because width decreases
and height cannot exceed the shorter boundary.

So we greedily discard the smaller height each step.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Two Pointers (Greedy Optimization)

Key Learning:
Whenever area/optimization depends on two ends and shrinking width:
→ Move pointer with smaller constraint
*/



class Solution {
public:
    int maxArea(vector<int>& height) {

        // Two pointers at both ends of array
        int left = 0;
        int right = height.size() - 1;

        // Stores maximum water container found
        int max_water = 0;

        // Move pointers until they meet
        while(left < right)
        {
            // Compute height constrained by shorter line
            int h = min(height[left], height[right]);

            // Compute width between lines
            int w = right - left;

            // Current container area
            int curr_water = h * w;

            // Update maximum area
            max_water = max(max_water, curr_water);

            // Move pointer with smaller height inward
            if(height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return max_water;
    }
};
