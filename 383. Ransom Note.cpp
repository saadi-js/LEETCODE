/*
Problem 383. Ransom Note

Problem Statement:

Given two strings ransomNote and magazine, return true if ransomNote
can be constructed using the letters from magazine, and false otherwise.

Each letter in magazine can only be used once.

--------------------------------------------------

Intuition:

To construct the ransom note, every character needed must be available
in the magazine.

Instead of searching for each character repeatedly (which would be slow),
we can first count how many times each letter appears in the magazine.

Then, while traversing the ransom note:

- If a required character is unavailable, return false.
- Otherwise, use one occurrence of that character.

Since the strings contain only lowercase English letters, a frequency
array of size 26 is sufficient.

--------------------------------------------------

Key Idea:

Step 1: Count the frequency of every letter in the magazine.
Step 2: Traverse the ransom note.
Step 3: For every character:
        - If its frequency is zero, construction is impossible.
        - Otherwise, decrease its frequency.
Step 4: If all characters are successfully used, return true.

--------------------------------------------------

Approach:

1. Create a frequency array of size 26 initialized with zeros.
2. Traverse the magazine string and count the occurrences of each letter.
3. Traverse the ransom note.
4. For each character:
   - If its frequency is zero, return false.
   - Otherwise, decrement its frequency.
5. If every character is processed successfully, return true.

--------------------------------------------------

Example:

Input:

ransomNote = "aa"
magazine = "aab"

Frequency after processing magazine:

a → 2
b → 1

Process ransom note:

First 'a'
Frequency becomes 1

Second 'a'
Frequency becomes 0

All characters were available.

Output:
true

--------------------------------------------------

Counter Example:

Input:

ransomNote = "aa"
magazine = "ab"

Frequency:

a → 1
b → 1

Process ransom note:

First 'a'
Frequency becomes 0

Second 'a'
Frequency is already 0

Construction is impossible.

Output:
false

--------------------------------------------------

Why This Works:

The frequency array stores exactly how many copies of each character
are available.

Each time a character is used, its count is decreased.

If a character's frequency becomes zero before all required occurrences
are used, it means the magazine does not contain enough copies of that
character, so constructing the ransom note is impossible.

--------------------------------------------------

Time Complexity: O(n + m)

Where:
- n = length of magazine
- m = length of ransomNote

Each string is traversed exactly once.

--------------------------------------------------

Space Complexity: O(1)

The frequency array always has size 26, regardless of the input size.

--------------------------------------------------

Pattern Used:
Hashing / Frequency Counting

Key Learning:

1. A fixed-size frequency array is more efficient than a HashMap when the character set is known.
2. Counting frequencies first allows constant-time lookup for every character.
3. Decrementing the frequency simulates using a character exactly once.
4. Frequency counting is a common technique for string comparison and anagram-related problems.
*/

class Solution {
public:
    bool canConstruct(string ran, string mag) {

        vector<int> freq(26, 0);

        // Step 1: Count frequency of letters in magazine
        for(char x : mag)
        {
            freq[x - 'a']++;
        }

        // Step 2: Check if ransom note can be constructed
        for(char x : ran)
        {
            if(freq[x - 'a'] == 0)
            {
                return false;
            }

            freq[x - 'a']--;
        }

        return true;
    }
};
