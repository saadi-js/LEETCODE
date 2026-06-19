/*
Problem 20. Valid Parentheses

Problem Statement:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

A string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Intuition:
This is a classic stack problem where we track the most recent unmatched opening bracket.

We push opening brackets onto a stack and try to match them with closing brackets.

Key Idea:
Use a stack to maintain order of opening brackets.
For every closing bracket:
- It must match the top of the stack
- Otherwise, the string is invalid

Approach:
1. Initialize an empty stack.
2. Traverse each character in the string:
   a. If it's an opening bracket → push to stack
   b. If it's a closing bracket:
      - If stack is empty → invalid
      - Check if top matches correct opening bracket
      - If yes → pop
      - Else → invalid
3. At the end:
   - If stack is empty → valid
   - Otherwise → invalid

Example:
s = "([{}])"

Step-by-step:
( → push
[ → push
{ → push
} → match { → pop
] → match [ → pop
) → match ( → pop
→ valid

Why This Works:
Stack ensures LIFO order, which matches nested structure requirements.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern Used:
Stack (Matching / Pair Validation)

Key Learning:
Whenever order matters and you need to match pairs:
→ Use a stack
*/



class Solution {
public:
    bool isValid(string s) {

        // Stack to store opening brackets
        stack<char> st;

        // Traverse each character
        for(int i = 0; i < s.size(); i++)
        {
            // If opening bracket → push to stack
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                st.push(s[i]);
            }
            else
            {
                // If closing bracket but stack is empty → invalid
                if(st.empty())
                {
                    return false;
                }

                // Check matching pair with top of stack
                if( (st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']') )
                {
                    st.pop(); // valid match
                }
                else
                {
                    return false; // mismatch
                }
            }
        }

        // Valid only if all brackets matched
        return st.empty();
    }
};
