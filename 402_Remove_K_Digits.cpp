/*
Problem 402. Remove K Digits

Problem Statement:
Given a string num representing a non-negative integer and an integer k,
remove k digits from the number so that the resulting number is the smallest possible.

Return the result as a string. Remove leading zeros from the result.
If the result is empty, return "0".

--------------------------------------------------

Intuition:

To get the smallest number, we want to remove larger digits that appear
before smaller digits — because a large digit in a higher position
contributes more to the overall value.

A greedy approach using a monotonic stack naturally handles this:
keep digits in increasing order and pop larger ones when a smaller
digit arrives, as long as we still have removals left (k > 0).

--------------------------------------------------

Key Idea:

Maintain a monotonic increasing stack of digits.

For each digit:
- While stack is not empty AND k > 0 AND top > current digit:
    pop the top (remove a larger digit)
    decrement k
- Push current digit

After the loop, if k > 0 still, remove from the end of the stack.

Finally strip leading zeros and handle empty result.

--------------------------------------------------

Approach:

1. Traverse each character in num:
   - While stack not empty, k > 0, and stack top > current char:
       pop and decrement k
   - Push current char

2. If k > 0 after loop:
   - Pop remaining k elements from top of stack

3. Build result string from stack, reverse it.

4. Strip leading zeros using a pointer.

5. Return result or "0" if empty.

--------------------------------------------------

Example:

num = "1432219", k = 3

Process:
1 → push → [1]
4 → push → [1,4]
3 → pop 4 (k=2), push 3 → [1,3]
2 → pop 3 (k=1), push 2 → [1,2]
2 → push → [1,2,2]
1 → pop 2 (k=0), push 1 → [1,2,1]
9 → push → [1,2,1,9]

Result: "1219"

--------------------------------------------------

Example 2 (leading zeros):

num = "10200", k = 1

Pop 1 → "0200" → strip leading zeros → "200"

--------------------------------------------------

Why This Works:

The monotonic increasing stack ensures that digits are always in
non-decreasing order. Popping a larger digit before a smaller one
is always beneficial because it reduces value at a higher position.

--------------------------------------------------

Time Complexity: O(n)

Each digit is pushed and popped at most once.

--------------------------------------------------

Space Complexity: O(n)

Stack stores at most n digits.

--------------------------------------------------

Pattern Used:
Monotonic Stack (Greedy Digit Removal)

Key Learning:

1. Monotonic stack is ideal for "remove elements to minimize/maximize"
   problems on sequences.
2. Always handle the case where k > 0 after the main loop — remove
   from the end (largest remaining digits).
3. Leading zero stripping is a required post-processing step.
4. Return "0" explicitly when the result string becomes empty.
*/



class Solution {
public:
    string removeKdigits(string num, int k) {

        // Monotonic increasing stack of digits
        stack<char> st;

        // Process each digit
        for(char x : num)
        {
            // Remove larger digits before current smaller digit
            while(!st.empty() && k > 0 && st.top() > x)
            {
                st.pop();
                k--;
            }

            st.push(x);
        }

        // If removals remain, remove from the end (largest digits)
        while(!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }

        // Build result string from stack
        string ans = "";

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // Stack gives reverse order
        reverse(ans.begin(), ans.end());

        // Strip leading zeros
        int i = 0;

        while(i < ans.size() && ans[i] == '0')
        {
            i++;
        }

        ans = ans.substr(i);

        // Return "0" if result is empty
        return ans.empty() ? "0" : ans;
    }
};
