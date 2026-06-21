/*
Problem 844. Backspace String Compare

Problem Statement:
Given two strings s and t, compare them after processing backspaces ('#').
A '#' removes the previous character if it exists.

Return true if both final strings are equal.

Intuition:
Instead of simulating string editing directly, we simulate a stack behavior:
- normal character → push
- '#' → pop (if possible)

Key Idea:
Each string is processed into its final form, then compared.

Approach:
1. Process each string using a stack:
   - If char != '#', push into stack
   - If char == '#', pop if stack not empty
2. Convert stack to string
3. Compare both results

Example:

s = "ab#c"
→ "ac"

t = "ad#c"
→ "ac"

Output: true

Why This Works:
Stack naturally models undo/backspace behavior.

Time Complexity: O(n + m)
Space Complexity: O(n + m)

Pattern Used:
Stack / Simulation

Key Learning:
Whenever you see “backspace / undo / delete previous character”,
use stack or two-pointer reverse traversal.
*/




class Solution {
public:

    // Helper function to process backspaces
    string helper(string s)
    {
        stack<char> st;

        // Build final string using stack behavior
        for(char c : s)
        {
            if(c != '#')
            {
                st.push(c);
            }
            else if(!st.empty())
            {
                st.pop();
            }
        }

        // Convert stack to string
        string result = "";

        while(!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }

    bool backspaceCompare(string s, string t) {

        // Process both strings
        string s1 = helper(s);
        string s2 = helper(t);

        // Compare final results
        return s1 == s2;
    }
};
