/*
Problem 1047. Remove All Adjacent Duplicates In String

Problem Statement:
Given a string s, repeatedly remove adjacent duplicate characters
until no such pairs remain. Return the final string.

Intuition:
We need to eliminate pairs of identical adjacent characters.
When a character matches the last kept character, both cancel out.

This naturally follows a stack behavior:
- Keep characters in a stack
- If current character equals stack top → remove top (cancel pair)
- Otherwise → push character

Key Idea:
Use stack to simulate dynamic removal of adjacent duplicates.

Approach:
1. Traverse string from left to right.
2. For each character:
   - If stack is not empty AND top == current char → pop
   - Else → push current char
3. After traversal, stack contains final characters.
4. Build result string from stack and reverse it.

Example:

Input:
s = "abbaca"

Process:
a → push
b → push
b → pop (duplicate pair removed)
a → push
c → push
a → push

Result stack: "a c a"

Output:
"ca"

Why This Works:
Adjacent duplicates are resolved immediately using LIFO order.
Each character is processed once, and invalid pairs are removed instantly.

Time Complexity: O(n)

Space Complexity: O(n)

Pattern Used:
Stack / Adjacent Pair Elimination

Key Learning:
When you need to repeatedly remove adjacent matching elements,
a stack provides optimal single-pass resolution.
*/



class Solution {
public:

    string removeDuplicates(string s) {

        // Stack to store processed characters
        stack<char> st;

        // Traverse input string
        for(int i = 0; i < s.size(); i++)
        {
            // If stack not empty and top matches current character
            if(!st.empty() && s[i] == st.top())
            {
                // Remove duplicate pair
                st.pop();
            }
            else
            {
                // Otherwise store character
                st.push(s[i]);
            }
        }

        // Build result string from stack
        string ans = "";

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // Reverse because stack is LIFO
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
