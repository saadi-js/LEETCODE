/*
Problem 66. Plus One

Problem Statement:
You are given a large integer represented as an integer array digits,
where each digits[i] is a digit of the number.

Increment the integer by one and return the resulting array.

Intuition:
Instead of converting the entire array into a number,
we simulate addition starting from the least significant digit.

Key Idea:
We simulate "carry propagation" from right to left.

If a digit is less than 9:
- simply increment and return immediately.

If a digit is 9:
- it becomes 0 and carry moves left.

If all digits are 9:
- result becomes 1000...0 (extra leading 1 is added)

Approach:
1. Traverse digits from right to left.
2. If digit < 9:
   - increment it
   - return result immediately
3. Else:
   - set digit to 0 (carry continues)
4. If loop ends:
   - insert 1 at beginning

Example:

Input: [1,2,3]
Output: [1,2,4]

Input: [9,9,9]
Step:
999 → 000 + carry → 1000

Why This Works:
We mimic manual addition exactly as done in arithmetic,
handling carry propagation efficiently.

Time Complexity: O(n)
Space Complexity: O(1) extra (excluding output)

Pattern Used:
Simulation / Carry propagation

Key Learning:
Digit-based array problems often simulate elementary arithmetic rules.
*/



class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {

        // Traverse from last digit (least significant digit)
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            // If current digit is less than 9
            if(digits[i] < 9)
            {
                // Simply increment and return
                digits[i] += 1;
                return digits;
            }
            else
            {
                // If digit is 9, it becomes 0 (carry forward)
                digits[i] = 0;
            }
        }

        // If all digits were 9, insert 1 at beginning
        digits.insert(digits.begin(), 1);

        return digits;
    }
};
