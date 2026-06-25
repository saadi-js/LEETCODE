/*
Problem 136. Single Number

Problem Statement:
Given a non-empty array of integers nums, every element appears
twice except for one. Find that single element.

You must implement a solution with:
- Linear time complexity O(n)
- Constant space complexity O(1)

--------------------------------------------------

Intuition:

A HashMap solution would count frequencies and find the element
with count 1, but that uses O(n) space.

We need O(1) space. This is where XOR becomes powerful.

--------------------------------------------------

Key Idea:

XOR has two critical properties:

1. a ^ a = 0       → any number XORed with itself is 0
2. a ^ 0 = a       → any number XORed with 0 is itself
3. XOR is commutative and associative

So if we XOR all elements together:
- Every number that appears twice cancels out to 0
- The single number remains

--------------------------------------------------

Approach:

1. Initialize x = 0
2. XOR every element into x
3. Return x

--------------------------------------------------

Example:

nums = [4, 1, 2, 1, 2]

x = 0
x = 0 ^ 4 = 4
x = 4 ^ 1 = 5
x = 5 ^ 2 = 7
x = 7 ^ 1 = 6
x = 6 ^ 2 = 4

Output: 4

Why?
1 ^ 1 = 0
2 ^ 2 = 0
4 ^ 0 = 4

--------------------------------------------------

Why This Works:

XOR is essentially binary addition without carry.
When you XOR a number with itself, every bit cancels out.
Since all duplicate numbers cancel, only the unique number
remains in x after processing the entire array.

--------------------------------------------------

Time Complexity: O(n)

Single pass through the array.

--------------------------------------------------

Space Complexity: O(1)

Only one integer variable used.

--------------------------------------------------

Pattern Used:
Bit Manipulation (XOR)

Key Learning:

1. XOR is the go-to tool whenever a problem involves pairs
   that cancel out, or finding a unique element.
2. a ^ a = 0 and a ^ 0 = a are the two rules to memorize.
3. This pattern extends to Single Number II and III where
   elements appear 3 times instead of 2.
4. XOR solves in O(1) space what HashMap solves in O(n) space.
*/



class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // XOR accumulator — starts at 0 (identity for XOR)
        int x = 0;

        // XOR every element — duplicates cancel out
        for(int n : nums)
        {
            x ^= n;
        }

        // Only the unique element remains
        return x;
    }
};
