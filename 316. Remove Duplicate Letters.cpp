/*
Problem 316. Remove Duplicate Letters

Problem Statement:

Given a string s, remove duplicate letters so that every letter appears
exactly once.

Among all possible results, return the lexicographically smallest string.

--------------------------------------------------

Intuition:

We need to satisfy two conditions:

1. Every character should appear only once.
2. The final string should be lexicographically smallest.

Simply keeping the first occurrence does not always produce the smallest
string.

Instead, while processing each character, we decide whether a previously
chosen character should remain or be replaced by a smaller one.

A stack helps us build the answer while allowing us to remove characters
that can safely appear later.

--------------------------------------------------

Key Idea:

Step 1: Count the remaining frequency of every character.
Step 2: Maintain a stack representing the current answer.
Step 3: Maintain a boolean array indicating whether a character is
        already present in the stack.
Step 4: For every character:
        - Decrease its remaining frequency.
        - Skip it if it is already in the stack.
        - Otherwise, remove larger characters from the stack while:
            • they are lexicographically larger,
            • and they appear again later.
        - Push the current character.
Step 5: Convert the stack into the final string.

--------------------------------------------------

Approach:

1. Count the frequency of every character.
2. Create:
   - a stack for the answer.
   - a boolean array `instack`.
3. Traverse every character:
   - Decrease its remaining frequency.
   - If already in the stack, continue.
   - While:
       • stack is not empty,
       • current character is smaller than stack top,
       • stack top appears later again,
     pop the stack.
   - Push the current character.
   - Mark it as present in the stack.
4. Pop every character from the stack.
5. Reverse the string and return it.

--------------------------------------------------

Example:

Input:

s = "bcabc"

Frequency:

b → 2
c → 2
a → 1

Process:

Read 'b'

Stack:
[b]

------------------

Read 'c'

Stack:
[b,c]

------------------

Read 'a'

'a' is smaller than 'c'
and 'c' appears later.

Pop c.

'a' is smaller than 'b'
and 'b' appears later.

Pop b.

Push a.

Stack:
[a]

Continue...

Final Stack:

[a,b,c]

Output:

"abc"

--------------------------------------------------

Another Example:

Input:

s = "cbacdcbc"

Output:

"acdb"

This is the smallest possible string containing every distinct
character exactly once.

--------------------------------------------------

Why This Works:

The stack always stores the smallest valid answer built so far.

Whenever a smaller character appears, we remove larger characters only
if they can be added again later.

The frequency array tells us whether it is safe to remove a character.

The `instack` array guarantees that every character appears only once.

--------------------------------------------------

Time Complexity: O(n)

Each character is pushed onto the stack at most once and popped at most
once.

Overall complexity is O(n).

--------------------------------------------------

Space Complexity: O(1)

The stack, frequency array, and boolean array store at most 26 lowercase
letters.

--------------------------------------------------

Pattern Used:
Monotonic Stack + Greedy

Key Learning:

1. A monotonic stack can produce the lexicographically smallest valid sequence.
2. Before removing an element, ensure it appears again later.
3. A frequency array helps determine whether it is safe to pop a character.
4. An `instack` array prevents duplicate insertions while allowing characters
   to be reinserted after being popped.
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {

        // Count remaining frequency of each character
        vector<int> freq(26, 0);

        for(char ch : s)
        {
            freq[ch - 'a']++;
        }

        stack<char> st;

        // Tracks whether a character is already in the stack
        vector<bool> instack(26, false);

        for(char ch : s)
        {
            freq[ch - 'a']--;

            // Skip duplicates
            if(instack[ch - 'a'])
            {
                continue;
            }

            // Remove larger characters that appear again later
            while(!st.empty() &&
                  ch < st.top() &&
                  freq[st.top() - 'a'] > 0)
            {
                instack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            instack[ch - 'a'] = true;
        }

        // Build the answer
        string ans = "";

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
