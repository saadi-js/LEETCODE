/*
Problem 344. Reverse String

Problem Statement:
Write a function that reverses a string. The input string is given
as an array of characters s.

You must do this by modifying the input array in-place with O(1)
extra memory.

--------------------------------------------------

Intuition:

Reversing a string means swapping the first character with the
last, the second with the second-last, and so on until the
two pointers meet in the middle.

This is the most fundamental two-pointer application.

--------------------------------------------------

Key Idea:

Two pointers converging from both ends:
- left  → starts at index 0
- right → starts at index n-1

Swap s[left] and s[right], then move both inward.
Stop when left >= right (pointers have crossed or met).

--------------------------------------------------

Approach:

1. Initialize left = 0, right = s.size() - 1.
2. While left <= right:
   - Swap s[left] and s[right]
   - left++
   - right--
3. Array is reversed in-place.

--------------------------------------------------

Example:

s = ['h','e','l','l','o']

Step 1: swap(h, o) → ['o','e','l','l','h']
Step 2: swap(e, l) → ['o','l','l','e','h']
Step 3: left == right (middle) → stop

Output: ['o','l','l','e','h']

--------------------------------------------------

Even Length Example:

s = ['a','b','c','d']

Step 1: swap(a, d) → ['d','b','c','a']
Step 2: swap(b, c) → ['d','c','b','a']
Step 3: left > right → stop

Output: ['d','c','b','a']

--------------------------------------------------

Why This Works:

Each swap correctly repositions two characters simultaneously.
After n/2 swaps, every character is in its mirrored position.

--------------------------------------------------

Time Complexity: O(n)

n/2 swaps — each element is touched exactly once.

--------------------------------------------------

Space Complexity: O(1)

In-place swaps using only pointer variables.

--------------------------------------------------

Pattern Used:
Two Pointers (In-place Reversal)

Key Learning:

1. Two-pointer reversal is the building block for many harder
   problems: Reverse Words in a String, Rotate Array, Palindrome.
2. The loop condition left <= right handles both odd and even
   length arrays correctly.
3. std::swap is clean but the same result is achievable with
   a temporary variable for explicit understanding.
*/



class Solution {
public:
    void reverseString(vector<char>& s) {

        // Left pointer starts at beginning
        int left = 0;

        // Right pointer starts at end
        int right = s.size() - 1;

        // Converge pointers toward center
        while(left <= right)
        {
            // Swap characters at both ends
            swap(s[left], s[right]);

            // Move pointers inward
            left++;
            right--;
        }
    }
};
