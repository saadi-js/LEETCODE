/*
Problem 925. Long Pressed Name

Problem Statement:
Given two strings name and typed, determine if typed could have been
produced by long pressing some characters in name.

A character in name may be typed once or may be long pressed
(repeated multiple times) in typed.

Intuition:
We compare both strings using two pointers.
We allow extra repeated characters in typed, but only if they match
the previous character in typed.

Key Idea:
Two-pointer traversal with controlled repetition handling:

- If characters match → move both pointers
- If mismatch:
  → it is only valid if typed character is repeating (long press)
- Otherwise → invalid

Approach:
1. Initialize two pointers:
   - np → pointer for name
   - tp → pointer for typed

2. Traverse both strings:
   - If characters match → move both
   - Else if typed[tp] equals previous typed character → skip tp
   - Else → return false

3. After traversal:
   - Ensure all characters in name are consumed
   - Remaining typed characters must be valid repeats

Example:

name  = "alex"
typed = "aaleex"

Steps:
a → a (match)
l → l (match)
e → e (match)
x → x (match)

Extra:
typed has extra repeated characters → valid

Output: true

Why This Works:
Typed string is allowed to "stretch" characters,
but not introduce new ones or change order.

Time Complexity: O(n + m)

Space Complexity: O(1)

Pattern Used:
Two Pointers + Controlled Matching

Key Learning:
When extra repetitions are allowed but order must be preserved,
use two pointers with validation of repeated characters.
*/



class Solution {
public:

    bool isLongPressedName(string name, string typed) {

        // Pointer for name
        int np = 0;

        // Pointer for typed string
        int tp = 0;

        // Traverse both strings
        while(np < name.size() && tp < typed.size())
        {
            // Case 1: characters match → move both pointers
            if(name[np] == typed[tp])
            {
                np++;
                tp++;
            }

            // Case 2: repeated character in typed (long press)
            else if(tp >= 1 && typed[tp] == typed[tp - 1])
            {
                tp++;
            }

            // Case 3: invalid mismatch
            else
            {
                return false;
            }
        }

        // If name is not fully matched → invalid
        if(np != name.size())
        {
            return false;
        }

        // Ensure remaining typed characters are valid repeats
        else
        {
            while(tp < typed.size())
            {
                if(typed[tp] != typed[tp - 1])
                {
                    return false;
                }
                tp++;
            }
        }

        return true;
    }
};
