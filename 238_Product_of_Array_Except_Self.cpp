/*
Problem 238. Product of Array Except Self

Problem Statement:
Given an integer array nums, return an array answer such that:

answer[i] = product of all elements of nums except nums[i].

The solution must run in O(n) time and without using division.

--------------------------------------------------

Intuition:

A brute force solution would be:

For every index i:
    Multiply all elements except nums[i].

This would require O(n²) time.

Instead, notice that:

answer[i] = (product of all elements to the left of i)
            ×
            (product of all elements to the right of i)

For example:

nums = [1,2,3,4]

For index 2 (value = 3):

Left Product  = 1 × 2 = 2
Right Product = 4

answer[2] = 2 × 4 = 8

--------------------------------------------------

Optimal Idea:

For every position we need:

prefix product × suffix product

Example:

nums = [1,2,3,4]

Prefix Products:

Index:  0  1  2  3
Value:  1  1  2  6

Suffix Products:

Index:  0  1  2  3
Value: 24 12  4  1

Answer:

1×24 = 24
1×12 = 12
2×4  = 8
6×1  = 6

Result = [24,12,8,6]

--------------------------------------------------

Space Optimization:

Instead of storing both prefix and suffix arrays:

1. Store prefix products directly inside answer array.
2. Maintain a single variable suffix.
3. Traverse from right to left.
4. Multiply current prefix product by suffix product.

This reduces extra space from O(n) to O(1)
(excluding the output array).

--------------------------------------------------

Algorithm:

1. Create answer array initialized with 1.
2. Fill answer with prefix products.
3. Initialize suffix = 1.
4. Traverse from right to left:
      suffix *= next element
      answer[i] *= suffix
5. Return answer.

--------------------------------------------------

Example Walkthrough:

nums = [1,2,3,4]

Initial:

ans = [1,1,1,1]

After Prefix Pass:

ans = [1,1,2,6]

Right-to-Left Pass:

suffix = 4
ans[2] = 2 × 4 = 8

suffix = 12
ans[1] = 1 × 12 = 12

suffix = 24
ans[0] = 1 × 24 = 24

Final:

[24,12,8,6]

--------------------------------------------------

Why This Works:

For every index i:

answer[i]
=
(product of elements before i)
×
(product of elements after i)

The first pass stores left products.

The second pass supplies right products.

Multiplying them gives exactly the required answer.

--------------------------------------------------

Time Complexity: O(n)

One left-to-right traversal.
One right-to-left traversal.

Total = O(n)

--------------------------------------------------

Space Complexity: O(1)

Ignoring the output array.

Only one extra variable (suffix) is used.

--------------------------------------------------

Pattern Used:
Prefix Sum / Prefix Product
+
Suffix Product

Key Learning:

1. Whenever a problem asks for information excluding the current index,
   think about Prefix and Suffix techniques.

2. Prefix and Suffix arrays often reduce O(n²) solutions to O(n).

3. Space can frequently be optimized by reusing the output array.

4. This is one of the most important array interview problems.
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // Size of the input array
        int n = nums.size();

        // Answer array initialized with 1
        // Initially it will store prefix products
        vector<int> ans(n, 1);

        // These arrays were part of an alternative solution
        // using separate prefix and suffix arrays
        // vector<int> prefix(n,1);
        // vector<int> sufix(n,1);

        // Build prefix products
        // ans[i] stores product of all elements before index i
        for(int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Stores running suffix product
        int sufix = 1;

        // Traverse from right to left
        for(int i = n - 2; i >= 0; i--)
        {
            // Update suffix product using the element
            // immediately to the right
            sufix *= nums[i + 1];

            // Multiply prefix product with suffix product
            ans[i] *= sufix;
        }

        // Return final answer array
        return ans;
    }
};
