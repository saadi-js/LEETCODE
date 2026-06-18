/*
Problem 151. Reverse Words in a String

Problem Statement:

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters.

Return a string of the words in reverse order, separated by a single space,
with no leading or trailing spaces.

--------------------------------------------------

Intuition:

A direct approach would be:
- Split the string into words
- Store them in an array
- Reverse the array
- Join them back

But we can optimize space usage using in-place string manipulation.

--------------------------------------------------

Key Idea:

We reverse the entire string first.

Then:
- Each word becomes reversed internally
- We fix it by reversing each word again

So effectively:
1. Reverse whole string
2. Extract words
3. Reverse each word
4. Build final result

--------------------------------------------------

Approach:

1. Reverse the entire string s.
2. Traverse the string:
   - Extract each word
   - Reverse the word back to correct order
   - Append it to result string
3. Ensure words are separated by single spaces
4. Remove leading space from final result

--------------------------------------------------

Example:

Input:
"the sky is blue"

Step 1: reverse entire string
"eulb si yks eht"

Step 2: extract words and reverse each:

"blue"
"is"
"sky"
"the"

Final result:
"blue is sky the"

--------------------------------------------------

Why This Works:

Reversing the full string changes word order,
but also reverses characters inside words.

So we fix word-level reversal individually.

--------------------------------------------------

Time Complexity: O(n)

Each character is visited multiple times (constant number of passes).

--------------------------------------------------

Space Complexity: O(1) extra space (excluding output string)

We only use temporary word storage.

--------------------------------------------------

Pattern Used:
String Manipulation + Reversal Technique

Key Learning:

1. Full reversal + partial correction is a powerful technique.
2. Helps avoid using extra data structures like vectors of strings.
3. Common trick in string interview problems.
*/



class Solution {
public:
    string reverseWords(string s) {

        // Length of input string
        int n = s.length();

        // Final answer string
        string ans = "";

        // Step 1: Reverse entire string
        reverse(s.begin(), s.end());

        // Traverse reversed string
        for(int i = 0; i < n; i++)
        {
            // Temporary string to store current word
            string word = "";

            // Extract characters until space
            while(i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }

            // Reverse word to restore correct order
            reverse(word.begin(), word.end());

            // Add word to result if not empty
            if(word.length() > 0)
            {
                ans += " " + word;
            }
        }

        // Remove leading space and return result
        return ans.substr(1);
    }
};
