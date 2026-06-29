/*
Problem 303. Range Sum Query - Immutable

Problem Statement:

Given an integer array nums, handle multiple queries of the form:

sumRange(left, right)

Return the sum of the elements between indices left and right (inclusive).

Since the array never changes, we can preprocess it to answer each query efficiently.

--------------------------------------------------

Intuition:

If we calculate the sum from index 0 up to every index beforehand,
then any range sum can be computed without traversing the array again.

Suppose we know:

prefix[i] = sum of elements from index 0 to i

Then,

Sum(left...right) =
prefix[right] - prefix[left - 1]

The only special case is when left = 0, because there is no
prefix[-1].

--------------------------------------------------

Key Idea:

Step 1: Precompute a prefix sum array.
Step 2: Store the cumulative sum up to every index.
Step 3: For each query:
        - If left == 0, return prefix[right].
        - Otherwise, subtract prefix[left - 1] from prefix[right].

This allows every query to be answered in constant time.

--------------------------------------------------

Approach:

1. Create a prefix sum array of the same size as nums.
2. Set:
   - prefix[0] = nums[0]
3. For every remaining index:
   - prefix[i] = prefix[i - 1] + nums[i]
4. For each query:
   - If left == 0, return prefix[right].
   - Otherwise, return prefix[right] - prefix[left - 1].

--------------------------------------------------

Example:

nums = [-2, 0, 3, -5, 2, -1]

Prefix Sum Array:

Index:   0   1   2   3   4   5
Nums:   -2   0   3  -5   2  -1
Prefix: -2  -2   1  -4  -2  -3

Query:

left = 2
right = 5

Sum =
prefix[5] - prefix[1]

= -3 - (-2)

= -1

Output:
-1

--------------------------------------------------

Counter Example:

nums = [5, 7, 2]

Query:

left = 0
right = 2

Since left is 0,

Answer =
prefix[2]

= 14

Output:
14

--------------------------------------------------

Why This Works:

The prefix sum array stores the cumulative sum up to every index.

Subtracting the cumulative sum before the left boundary removes
all unwanted elements, leaving only the desired range.

This avoids recomputing the sum for every query.

--------------------------------------------------

Time Complexity:

Constructor: O(n)

sumRange(): O(1)

--------------------------------------------------

Space Complexity: O(n)

The prefix sum array stores one cumulative sum for every element.

--------------------------------------------------

Pattern Used:
Prefix Sum

Key Learning:

1. Prefix sums are ideal when there are multiple range sum queries on an immutable array.
2. Preprocessing once can significantly reduce query time.
3. The formula:
   prefix[right] - prefix[left - 1]
   efficiently computes any range sum.
4. Always handle the special case when left = 0 separately.
*/

class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {

        prefix.resize(nums.size());

        prefix[0] = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {

        if(left == 0)
            return prefix[right];

        return prefix[right] - prefix[left - 1];
    }
};
