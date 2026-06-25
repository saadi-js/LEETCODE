/*
Problem 977. Squares of a Sorted Array

Problem Statement:
Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number sorted in
non-decreasing order.

--------------------------------------------------

Intuition:

The simplest approach is to square every element and then sort.
That is exactly what this solution does — square in-place then sort.

This is clean and readable, though not the most optimal approach.

--------------------------------------------------

Key Idea:

Step 1: Square every element in-place: nums[i] *= nums[i]
Step 2: Sort the squared array

Since the original array can contain negative numbers, squaring
can break the sorted order (e.g. [-4,-1,0,3,10] → [16,1,0,9,100]).
Sorting after squaring restores the correct order.

--------------------------------------------------

Approach:

1. Traverse nums and square each element in-place.
2. Sort the modified array.
3. Return nums.

--------------------------------------------------

Example:

nums = [-4,-1,0,3,10]

After squaring:
[16, 1, 0, 9, 100]

After sorting:
[0, 1, 9, 16, 100]

Output: [0,1,9,16,100]

--------------------------------------------------

Optimal Alternative (Two Pointers O(n)):

The sorted input means largest squares come from either end.
Use two pointers and fill result from back to front:

vector<int> ans(n);
int left = 0, right = n-1, pos = n-1;

while(left <= right) {
    if(abs(nums[left]) > abs(nums[right])) {
        ans[pos--] = nums[left] * nums[left++];
    } else {
        ans[pos--] = nums[right] * nums[right--];
    }
}

This avoids the O(n log n) sort entirely and runs in O(n).

--------------------------------------------------

Time Complexity: O(n log n)

Squaring is O(n), sorting is O(n log n).

--------------------------------------------------

Space Complexity: O(1)

In-place modification, no extra array.

--------------------------------------------------

Pattern Used:
Array / In-place Transformation + Sorting

Key Learning:

1. When the input is sorted but squaring breaks order, sorting
   after transformation is the simplest correct approach.
2. The optimal O(n) two-pointer solution exploits the fact that
   largest absolute values sit at both ends of the sorted array.
3. Knowing both solutions — simple sort and optimal two-pointer —
   shows depth of understanding in interviews.
*/



class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        // Step 1: Square every element in-place
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] *= nums[i];
        }

        // Step 2: Sort squared values in non-decreasing order
        sort(nums.begin(), nums.end());

        return nums;
    }
};
