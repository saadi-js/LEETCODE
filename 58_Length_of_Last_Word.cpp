/*
Problem 58. Length of Last Word

Problem Statement:
Given a string s consisting of words and spaces, return the length
of the last word in the string.

A word is defined as a maximal substring consisting of non-space characters.

Intuition:
We only care about the last word, so instead of scanning left-to-right,
we efficiently scan from the end.

We skip trailing spaces first, then count characters until we hit a space.

Key Idea:
Reverse traversal:
- Ignore trailing spaces
- Count characters of last word
- Stop when first word boundary is found

Approach:
1. Start from end of string
2. Skip all trailing spaces
3. Start counting characters
4. Stop when a space is encountered after counting begins
5. Return count

Example:
s = "Hello World"

Traversal from end:
d → o → r → l → d → count = 5

Output = 5

Why This Works:
The last word is always at the end of the string (ignoring spaces),
so backward traversal avoids unnecessary processing.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Reverse traversal / String scanning

Key Learning:
When only suffix information is needed, scanning from the end is optimal.
*/




class Solution {
public:

    int lengthOfLastWord(string s) {

        // Counter for last word length
        int count = 0;

        // Traverse string from end to start
        for(int i = s.size() - 1; i >= 0; i--)
        {
            // If current character is not space, it's part of a word
            if(s[i] != ' ')
            {
                count++;
            }

            // If we already started counting and hit a space → stop
            else if(count > 0)
            {
                break;
            }
        }

        // Return length of last word
        return count;
    }
};
