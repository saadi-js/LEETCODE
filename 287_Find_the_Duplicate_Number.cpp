/*
Problem 287. Find the Duplicate Number

Problem Statement:
Given an array nums containing n + 1 integers where each integer is in the range [1, n],
there is only one repeated number in nums. Return this repeated number.

Constraints:
- Must not modify array
- Must use constant extra space
- Must run in less than O(n²)

Intuition:
Treat the array as a linked list:
- Each index points to nums[index]
- This creates a cycle because a number is repeated

So the problem reduces to:
→ Detect cycle in a linked structure
→ Find entry point of the cycle (duplicate number)

Key Idea:
Use Floyd’s Cycle Detection Algorithm:
1. First phase: find intersection point (cycle detection)
2. Second phase: find cycle entry point (duplicate)

Mapping:
index → next node = nums[index]

Approach:
Phase 1: Detect cycle
- slow moves 1 step: slow = nums[slow]
- fast moves 2 steps: fast = nums[nums[fast]]
- stop when slow == fast

Phase 2: Find entry point
- reset slow to start (nums[0])
- move slow and fast one step at a time
- meeting point is duplicate number

Why This Works:
Since numbers are in range [1, n], they form a cycle in index mapping.
Duplicate creates the cycle entry point.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Floyd’s Cycle Detection (Linked List Simulation)

Key Learning:
Arrays with index-value mapping can behave like linked lists.
Cycle detection can solve duplicate-related constraints.
*/



class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Slow pointer starts at first element
        int slow = nums[0];

        // Fast pointer starts at first element
        int fast = nums[0];

        /*
        -------------------------
        PHASE 1: Detect cycle
        -------------------------
        */
        do
        {
            // Move slow by 1 step
            slow = nums[slow];

            // Move fast by 2 steps
            fast = nums[nums[fast]];

        } while(slow != fast);

        /*
        -------------------------
        PHASE 2: Find cycle entry
        -------------------------
        */

        // Reset slow pointer to start
        slow = nums[0];

        // Move both one step at a time
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        // Meeting point is duplicate number
        return slow;
    }
};
