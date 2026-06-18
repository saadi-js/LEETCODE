/*
Problem 496. Next Greater Element I

Problem Statement:

You are given two arrays nums1 and nums2 where nums1 is a subset of nums2.

For each element in nums1, find the next greater element in nums2.

The next greater element of x is the first greater element to the right of x in nums2.
If it does not exist, return -1.

--------------------------------------------------

Intuition:

A brute force approach would be:

For every element in nums1:
    Search it in nums2
    Then scan to the right to find the next greater element

This leads to O(n²) time complexity.

We need an optimized approach.

--------------------------------------------------

Key Idea:

We preprocess nums2 using a Monotonic Stack.

We compute:
    next greater element for every element in nums2

Then we store results in a hash map for O(1) lookup.

--------------------------------------------------

Monotonic Stack Concept:

We maintain a stack in decreasing order.

For each element:
- Pop all smaller or equal elements from stack
- The top of stack is the next greater element

--------------------------------------------------

Approach:

1. Create a hash map to store next greater element for each number.
2. Use a stack to process nums2 from right to left.
3. For each element:
   - Pop elements smaller than or equal to current
   - If stack is empty → no greater element (-1)
   - Else → stack top is next greater element
   - Push current element into stack
4. After preprocessing nums2:
   - For each element in nums1, directly fetch result from map

--------------------------------------------------

Example:

nums2 = [1,3,4,2]

Processing from right:

2 → -1
4 → -1
3 → 4
1 → 3

Map:
1 → 3
3 → 4
4 → -1
2 → -1

nums1 = [4,1,2]
Answer = [-1,3,-1]

--------------------------------------------------

Why This Works:

We avoid repeated scanning by precomputing answers for all elements
using a stack that maintains "useful candidates" only.

The stack always keeps elements in decreasing order,
so the next greater element is always at the top.

--------------------------------------------------

Time Complexity: O(n)

Each element is pushed and popped at most once.

--------------------------------------------------

Space Complexity: O(n)

For stack + hash map.

--------------------------------------------------

Pattern Used:
Monotonic Stack (Next Greater Element)

Key Learning:

1. Monotonic stack is used for "next greater/smaller element" problems.
2. Preprocessing helps convert O(n²) → O(n).
3. Stack maintains useful candidates only.
4. Very important interview pattern.
*/




class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // Map to store next greater element for each number
        unordered_map<int,int> m;

        // Stack to maintain decreasing order of elements
        stack<int> n;

        // Traverse nums2 from right to left
        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            // Remove all elements smaller or equal to current element
            while(!n.empty() && nums2[i] >= n.top())
            {
                n.pop();
            }

            // If stack is empty, no greater element exists
            if(n.empty())
            {
                m[nums2[i]] = -1;
            }
            else
            {
                // Top of stack is next greater element
                m[nums2[i]] = n.top();
            }

            // Push current element into stack
            n.push(nums2[i]);
        }

        // Build result for nums1 using precomputed map
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};
