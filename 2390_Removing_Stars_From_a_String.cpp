/*
Problem 2390. Removing Stars From a String

Problem Statement:
You are given a string s containing lowercase English letters and '*'.

In one operation:
- Choose a '*' character.
- Remove the closest non-star character to its left.
- Remove the '*' itself.

Return the string after all stars have been removed.

It is guaranteed that the operation can always be performed.

Intuition:
Whenever we encounter a '*', we need to remove the most recent
character that has not already been removed.

This is exactly the behavior of a stack:

- Letters → push into stack
- '*' → remove most recent letter (pop)

Key Idea:
Use a stack to maintain the characters that remain in the string.

For every character:
- If it is a normal character → push
- If it is '*' → pop the previously added character

At the end, the stack contains the final answer.

Approach:
1. Create an empty stack.
2. Traverse the string.
3. If current character is:
   - Letter → push into stack
   - '*' → pop top character
4. Extract all remaining characters from stack.
5. Reverse the result because stack returns characters in reverse order.
6. Return the final string.

Example:

Input:
s = "leet**cod*e"

Processing:

l → push
e → push
e → push
t → push

* → remove t
* → remove e

c → push
o → push
d → push

* → remove d

e → push

Remaining:
l e c o e

Output:
"lecoe"

Why This Works:
The closest non-star character to the left is always the most recently
added character that hasn't been removed.

A stack naturally provides this Last-In-First-Out behavior.

Time Complexity: O(n)

Space Complexity: O(n)

Pattern Used:
Stack / Undo Operations

Key Learning:
Whenever a problem asks to remove or undo the most recent valid element,
a stack is usually the correct data structure.
*/



class Solution {
public:
    string removeStars(string s) {

        // Stack stores characters that remain in the string
        stack<char> st;

        // Length of string
        int n = s.size();

        // Traverse the string
        for(int i = 0; i < n; i++)
        {
            // If star found
            if(s[i] == '*')
            {
                // Remove the most recent character
                st.pop();
            }
            else
            {
                // Store current character
                st.push(s[i]);
            }
        }

        // Build answer from remaining stack contents
        string ans = "";

        while(!st.empty())
        {
            // Characters come out in reverse order
            ans += st.top();

            st.pop();
        }

        // Reverse to restore original order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
