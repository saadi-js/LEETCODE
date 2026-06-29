/*
Problem 2540. Minimum Common Value

Problem Statement:

Given two integer arrays nums1 and nums2 sorted in non-decreasing order,
return the smallest integer that appears in both arrays.
If there is no common integer, return -1.

--------------------------------------------------

Intuition:

Since both arrays are already sorted, we do not need to compare every
element with every other element.

Instead, we can use two pointers:

- One pointer starts at the beginning of nums1.
- The other starts at the beginning of nums2.

If the current elements are equal, we have found the smallest common value.
Otherwise, move the pointer pointing to the smaller value because only that
array has a chance of catching up to the larger value.

--------------------------------------------------

Key Idea:

Step 1: Initialize two pointers at the beginning of both arrays.
Step 2: Compare the current elements.
Step 3: If they are equal, return the value.
Step 4: Move the pointer pointing to the smaller element.
Step 5: If one array ends without finding a match, return -1.

--------------------------------------------------

Approach:

1. Initialize two pointers:
   - i = 0 for nums1.
   - j = 0 for nums2.
2. While both pointers are within their arrays:
   - If nums1[i] == nums2[j], return the value.
   - If nums1[i] < nums2[j], increment i.
   - Otherwise, increment j.
3. If the loop finishes without finding a common value, return -1.

--------------------------------------------------

Example:

Input:

nums1 = [1,2,3,6]
nums2 = [2,3,4,5]

Process:

1 < 2
Move i

2 == 2

Smallest common value found.

Output:
2

--------------------------------------------------

Counter Example:

Input:

nums1 = [1,2,3]
nums2 = [4,5,6]

Process:

1 < 4 → Move i
2 < 4 → Move i
3 < 4 → Move i

nums1 is exhausted.

Output:
-1

--------------------------------------------------

Why This Works:

Because both arrays are sorted, any value smaller than the other current
value cannot become a match later.

Moving the pointer with the smaller value never skips a possible answer,
and the first match encountered is guaranteed to be the smallest common
value.

--------------------------------------------------

Time Complexity: O(n + m)

Where:
- n = size of nums1
- m = size of nums2

Each pointer moves at most once through its array.

--------------------------------------------------

Space Complexity: O(1)

Only two pointers are used.

--------------------------------------------------

Pattern Used:
Two Pointers / Sorted Arrays

Key Learning:

1. Two pointers are highly effective when both arrays are sorted.
2. Always move the pointer pointing to the smaller value.
3. The first common element encountered is automatically the minimum common value because of the sorted order.
4. This technique avoids the O(n × m) brute-force comparison of all pairs.
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int i = 0;
        int j = 0;

        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                return nums1[i];
            }

            if(nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return -1;
    }
};
