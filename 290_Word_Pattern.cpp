/*
Problem 290. Word Pattern

Problem Statement:
Given a pattern and a string s, find if s follows the same pattern.

"Follows" means a full match such that there is a bijection between
each letter in pattern and each non-empty word in s.

--------------------------------------------------

Intuition:

This is the same bidirectional mapping problem as Isomorphic Strings,
but instead of char→char we need char→string and string→char.

Each pattern character must map to exactly one word AND each word
must map back to exactly one pattern character.

--------------------------------------------------

Key Idea:

1. Split string s into individual words.
2. Check sizes match (pattern.size() == words.size()).
3. Use two maps:
   - mp1: char → string (pattern char to word)
   - mp2: string → char (word to pattern char)
4. For each position i, check both maps for conflicts.

--------------------------------------------------

Approach:

1. Parse s into vector<string> words by splitting on spaces.
2. If word count != pattern size → return false.
3. For each i:
   - If mp1[pattern[i]] exists and != words[i] → false
   - If mp2[words[i]] exists and != pattern[i] → false
   - Set mp1[pattern[i]] = words[i], mp2[words[i]] = pattern[i]
4. Return true.

--------------------------------------------------

Example:

pattern = "abba", s = "dog cat cat dog"

words = ["dog","cat","cat","dog"]

i=0: a→dog, dog→a (establish)
i=1: b→cat, cat→b (establish)
i=2: b already maps to cat, words[2]=cat ✓; cat maps to b, pattern[2]=b ✓
i=3: a already maps to dog, words[3]=dog ✓; dog maps to a, pattern[3]=a ✓

Output: true

--------------------------------------------------

Counter Example:

pattern = "abba", s = "dog dog dog dog"

i=1: b→dog, but dog already maps to a (mp2 conflict) → false

--------------------------------------------------

String Parsing:

Instead of using stringstream or split functions, we manually build
words by scanning for spaces — matching the simplicity of the rest
of the codebase.

--------------------------------------------------

Time Complexity: O(n)

One pass to parse, one pass to check mappings.

--------------------------------------------------

Space Complexity: O(n)

Storing words vector and two hash maps.

--------------------------------------------------

Pattern Used:
Hashing / Bidirectional Mapping (char ↔ string)

Key Learning:

1. Word Pattern is Isomorphic Strings with char→string instead of
   char→char — identical bidirectional mapping logic.
2. Always verify sizes match before mapping — avoids index errors.
3. Manual string splitting with a temp variable is clean and avoids
   library dependencies.
4. The bijection requirement (one-to-one both ways) always needs
   two separate maps.
*/



class Solution {
public:
    bool wordPattern(string pattern, string s) {

        // Split s into words manually
        vector<string> word;
        string temp = "";

        for(char ch : s)
        {
            if(ch == ' ')
            {
                word.push_back(temp);
                temp = "";
            }
            else
            {
                temp += ch;
            }
        }

        // Push last word
        word.push_back(temp);

        // Size mismatch → cannot match
        if(word.size() != pattern.size()) return false;

        // pattern char → word
        unordered_map<char, string> mp1;

        // word → pattern char
        unordered_map<string, char> mp2;

        for(int i = 0; i < pattern.size(); i++)
        {
            // Check if pattern[i] already maps to a different word
            if(mp1.count(pattern[i]) && mp1[pattern[i]] != word[i])
            {
                return false;
            }

            // Check if word[i] already maps to a different pattern char
            if(mp2.count(word[i]) && mp2[word[i]] != pattern[i])
            {
                return false;
            }

            // Establish bidirectional mapping
            mp1[pattern[i]] = word[i];
            mp2[word[i]] = pattern[i];
        }

        return true;
    }
};
