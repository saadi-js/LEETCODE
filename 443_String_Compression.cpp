/*
Problem 443. String Compression

Problem Statement:
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters:
- If the group length is 1, append the character to s.
- Otherwise, append the character followed by the group's length.

The compressed string must be stored in-place in chars.
Return the new length of the array.

--------------------------------------------------

Intuition:

We need to compress in-place without extra space.

The key observation is that the compressed result is always
shorter than or equal to the original, so we can safely write
the compressed characters back into the same array using a
write pointer (idx).

--------------------------------------------------

Key Idea:

Use two pointers:
- i   → read pointer scanning the original array
- idx → write pointer placing compressed characters

For each group of identical characters:
1. Record the character and count how many appear consecutively
2. Write the character at idx
3. If count > 1, write each digit of count as separate characters

--------------------------------------------------

Approach:

1. Initialize idx = 0, i = 0, n = chars.size().
2. While i < n:
   - Record current character ch = chars[i]
   - Count consecutive occurrences of ch (increment i each time)
   - Write ch at chars[idx++]
   - If count > 1:
       Convert count to string
       Write each digit character at chars[idx++]
   - i-- to correct for the extra increment at end of while loop
3. Return idx.

--------------------------------------------------

Example:

chars = ['a','a','b','b','c','c','c']

Group 1: 'a' × 2 → write 'a','2'
Group 2: 'b' × 2 → write 'b','2'
Group 3: 'c' × 3 → write 'c','3'

Result: ['a','2','b','2','c','3']
idx = 6

Output: 6

--------------------------------------------------

Example 2 (single character):

chars = ['a']

Group: 'a' × 1 → write only 'a' (no count)

Output: 1

--------------------------------------------------

Why i-- at the End of Each Group?

The inner while loop increments i until chars[i] != ch.
After the loop, i points to the first character of the next group.
The outer for loop then does i++, which would skip that character.
The i-- corrects for this so the outer loop increments to the
correct starting position of the next group.

--------------------------------------------------

Time Complexity: O(n)

Each character is read once and written at most twice
(character + up to log10(n) digits for count).

--------------------------------------------------

Space Complexity: O(1)

In-place modification. to_string() uses O(log count) temporary
space but this is negligible and bounded by O(log n).

--------------------------------------------------

Pattern Used:
Two Pointers / In-place String Compression

Key Learning:

1. When compressing in-place, use a write pointer (idx) that
   trails behind the read pointer (i).
2. Multi-digit counts must be written digit by digit as chars.
3. The i-- correction is a common pattern when the inner loop
   overshoots and the outer loop needs to compensate.
4. Always handle count == 1 separately to avoid writing "a1".
*/



class Solution {
public:
    int compress(vector<char>& chars) {

        // Write pointer for compressed result
        int idx = 0;

        // Total length of original array
        int n = chars.size();

        // Read pointer scanning through array
        for(int i = 0; i < n; i++)
        {
            // Record current character
            char ch = chars[i];

            // Count consecutive occurrences of ch
            int count = 0;

            while(i < n && chars[i] == ch)
            {
                count++;
                i++;
            }

            // Write the character
            chars[idx++] = ch;

            // Write count only if group size > 1
            if(count > 1)
            {
                // Convert count to string for multi-digit support
                string str = to_string(count);

                // Write each digit as a separate character
                for(char x : str)
                {
                    chars[idx++] = x;
                }
            }

            // Correct for extra increment from inner while loop
            i--;
        }

        // idx is the new length of the compressed array
        return idx;
    }
};
