/*
Problem 1299. Replace Elements with Greatest Element on Right Side

Problem Statement:
Given an array arr, replace every element in that array with the
greatest element among the elements to its right, and replace the
last element with -1.

Return the modified array after doing so.

--------------------------------------------------

Intuition:

A brute force approach scans the entire right portion of the array
for every element — O(n²).

We can do this in O(n) by traversing from right to left and
maintaining a running maximum of all elements seen so far.

--------------------------------------------------

Key Idea:

Traverse from right to left.

At each index i:
- Store current element in a temp variable
- Replace arr[i] with rightmax (greatest element to its right)
- Update rightmax = max(rightmax, current element)

The last element is always replaced by -1 (no elements to the right),
which is handled by initializing rightmax = -1.

--------------------------------------------------

Approach:

1. Initialize rightmax = -1.
2. Traverse from i = n-1 down to 0:
   - Store current = arr[i]
   - arr[i] = rightmax
   - rightmax = max(rightmax, current)
3. Return modified array.

--------------------------------------------------

Example:

arr = [17, 18, 5, 4, 6, 1]

Traversal right to left:

i=5: current=1,  arr[5]=-1,  rightmax=max(-1,1)=1
i=4: current=6,  arr[4]=1,   rightmax=max(1,6)=6
i=3: current=4,  arr[3]=6,   rightmax=max(6,4)=6
i=2: current=5,  arr[2]=6,   rightmax=max(6,5)=6
i=1: current=18, arr[1]=6,   rightmax=max(6,18)=18
i=0: current=17, arr[0]=18,  rightmax=max(18,17)=18

Output: [18,6,6,6,1,-1]

--------------------------------------------------

Why Traverse Right to Left?

At each position i, we need the maximum of all elements to
the right. By traversing right to left, rightmax already
contains exactly this information when we process index i.

Traversing left to right would require looking ahead, which
is why right-to-left is the natural direction here.

--------------------------------------------------

Why Store current Before Overwriting?

We overwrite arr[i] with rightmax, but we still need the
original arr[i] value to update rightmax for the next iteration.
Storing it in current prevents losing that value.

--------------------------------------------------

Time Complexity: O(n)

Single right-to-left pass.

--------------------------------------------------

Space Complexity: O(1)

In-place modification, only one temporary variable used.

--------------------------------------------------

Pattern Used:
Array / Right-to-Left Suffix Maximum

Key Learning:

1. Right-to-left traversal naturally provides suffix information.
2. Always save the current value before overwriting it in-place.
3. Initializing rightmax = -1 elegantly handles the last element
   requirement without a special case.
4. This suffix-max pattern also appears in problems like
   Product of Array Except Self (suffix product pass).
*/



class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        // Tracks maximum element seen to the right so far
        // Initialized to -1 for the last element's replacement
        int rightmax = -1;

        // Temporary storage for current element before overwrite
        int current;

        // Traverse from right to left
        for(int i = arr.size() - 1; i >= 0; i--)
        {
            // Save current element before overwriting
            current = arr[i];

            // Replace with greatest element to the right
            arr[i] = rightmax;

            // Update rightmax to include current element
            rightmax = max(rightmax, current);
        }

        return arr;
    }
};
