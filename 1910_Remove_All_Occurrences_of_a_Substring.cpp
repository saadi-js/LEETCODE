/*
Problem 1910. Remove All Occurrences of a Substring

Problem Statement:

Given a string s and a string part,
remove all occurrences of part from s until it no longer exists.

Return the final modified string.

--------------------------------------------------

Intuition:

A direct approach is:

- Find the substring "part" inside "s"
- Remove it
- Repeat until no more occurrences exist

This is essentially a repeated search-and-delete process.

--------------------------------------------------

Key Idea:

We repeatedly check if "part" exists in "s".
If found, we erase it and continue.

This is done using:
- string::find()
- string::erase()

--------------------------------------------------

Approach:

1. While the string contains the substring "part":
   - Find the first occurrence of "part"
   - Erase it from the string
2. Repeat until no more occurrences exist
3. Return final string

--------------------------------------------------

Example:

s = "daabcbaabcbc"
part = "abc"

Step-by-step:

daabcbaabcbc → remove "abc"
dabaababcbc  → remove "abc"
dababc       → remove "abc"
dab          → stop

Result = "dab"

--------------------------------------------------

Why This Works:

Each iteration removes at least one occurrence of "part",
and since string size keeps decreasing or stabilizing,
the process eventually terminates.

--------------------------------------------------

Time Complexity:

Worst case: O(n²)

Because:
- find() can be O(n)
- erase() can be O(n)
- repeated multiple times

--------------------------------------------------

Space Complexity: O(1)

In-place modification of the string.

--------------------------------------------------

Pattern Used:
String Search + Simulation (Greedy-like Removal)

Key Learning:

1. Repeated substring removal is often handled via simulation.
2. string::find + string::erase is a simple but not optimal approach.
3. Can be optimized using stack-based approaches.
4. Be careful of performance in large inputs.
*/



class Solution {
public:
    string removeOccurrences(string s, string part) {

        // Continue while string is not empty AND part exists in s
        while(s.length() > 0 && s.find(part) < s.length())
        {
            // Find first occurrence of substring "part"
            int pos = s.find(part);

            // Erase substring starting at pos with length of part
            s.erase(pos, part.length());
        }

        // Return final modified string
        return s;
    }
};
