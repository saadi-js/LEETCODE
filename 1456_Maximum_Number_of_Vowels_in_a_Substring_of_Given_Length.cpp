/*
Problem 1456. Maximum Number of Vowels in a Substring of Given Length

Problem Statement:
Given a string s and an integer k, return the maximum number of vowel letters
contained in any substring of s with length exactly k.

Vowels are:
a, e, i, o, u (both uppercase and lowercase are handled in this solution).

Intuition:
Since every valid substring must have a fixed size k, repeatedly counting vowels
for every substring would lead to unnecessary work.

Instead, we can count vowels in the first window of size k and then slide the
window one character at a time.

When the window moves:
- Add the contribution of the new incoming character.
- Remove the contribution of the outgoing character.

This allows us to maintain the vowel count efficiently.

Key Idea:
Use a Sliding Window of fixed size k.

Maintain:
- count = vowels in current window
- maxcount = maximum vowels seen so far

For every window shift:
1. Add the new character entering the window.
2. Remove the character leaving the window.
3. Update maximum count.

Approach:
1. Create a helper function isvowel() to check whether a character is a vowel.
2. Count vowels in the first k characters.
3. Store this value as the initial maximum.
4. Slide the window from index k to the end of the string.
5. If the incoming character is a vowel, increment count.
6. If the outgoing character is a vowel, decrement count.
7. Update maxcount after every shift.
8. Return maxcount.

Example:
s = "abciiidef"
k = 3

First window = "abc"
Vowels = 1

Slide:

"bci" -> 1 vowel
"cii" -> 2 vowels
"iii" -> 3 vowels
"iid" -> 2 vowels
"ide" -> 2 vowels
"def" -> 1 vowel

Maximum = 3

Why This Works:
The window size never changes.

At every step:
- One character enters.
- One character leaves.

Instead of recounting all k characters again, we update the count using only
these two characters, giving an efficient solution.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Sliding Window (Fixed Size)

Key Learning:
Whenever the problem asks for information about every subarray or substring of
fixed size k, think about a Fixed Size Sliding Window approach.
*/



class Solution {
public:

    // Helper function to check whether a character is a vowel
    bool isvowel(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
           ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        {
            return true;
        }
        else
            return false;
    }

    int maxVowels(string s, int k) {

        // Stores number of vowels in current window
        int count = 0;

        // Count vowels in the first window of size k
        for(int i = 0; i < k; i++)
        {
            if(isvowel(s[i]))
            {
                count++;
            }
        }

        // Initialize answer with first window's vowel count
        int maxcount = count;

        // Slide the window through the string
        for(int i = k; i < s.length(); i++)
        {
            // Add the new character entering the window
            if(isvowel(s[i]))
            {
                count++;
            }

            // Remove the character leaving the window
            if(isvowel(s[i-k]))
            {
                count--;
            }

            // Update maximum vowel count found so far
            maxcount = max(count, maxcount);
        }

        // Return maximum vowels in any window of size k
        return maxcount;
    }
};
