/*
Problem 692. Top K Frequent Words

Problem Statement:

Given an array of strings words and an integer k, return the k most
frequent words.

The answer should be sorted:

- By descending frequency.
- If two words have the same frequency, the lexicographically smaller
  word should come first.

--------------------------------------------------

Intuition:

The first step is to count how many times each word appears.

A HashMap efficiently stores these frequencies.

Instead of sorting every word, we maintain only the k best candidates
using a Min Heap.

The tricky part is handling ties:

- Smaller frequency should have higher priority for removal.
- If two words have the same frequency, the lexicographically larger
  word should have higher priority for removal because the final answer
  requires lexicographically smaller words first.

A custom comparator allows us to enforce these rules.

--------------------------------------------------

Key Idea:

Step 1: Count the frequency of every word.
Step 2: Store (frequency, word) pairs in a Min Heap with a custom comparator.
Step 3: If the heap size exceeds k, remove the least desirable element.
Step 4: Extract the remaining words from the heap.
Step 5: Reverse the result because elements are removed from lowest
        priority to highest priority.

--------------------------------------------------

Approach:

1. Build a frequency map using an unordered_map.
2. Create a Min Heap with a custom comparator.
3. For every (word, frequency):
   - Push the pair into the heap.
   - If heap size exceeds k, pop the top element.
4. Extract every word from the heap.
5. Reverse the extracted list.
6. Return the answer.

--------------------------------------------------

Example:

Input:

words = ["i","love","leetcode","i","love","coding"]
k = 2

Frequency Map:

i → 2
love → 2
leetcode → 1
coding → 1

Heap keeps only the two best words.

Since "i" and "love" have equal frequencies,
lexicographically smaller word comes first.

Output:

["i","love"]

--------------------------------------------------

Counter Example:

Input:

words = ["the","is","the","is","sun"]
k = 2

Frequency Map:

the → 2
is → 2
sun → 1

Both "the" and "is" have equal frequency.

Lexicographical order:

"is" < "the"

Output:

["is","the"]

--------------------------------------------------

Why This Works:

The custom comparator ensures that the least desirable element is always
placed at the top of the Min Heap.

Priority for removal:

1. Smaller frequency.
2. If frequencies are equal, lexicographically larger word.

Therefore, after processing all unique words, only the best k candidates
remain.

Reversing the extracted order produces the required ordering:

- Highest frequency first.
- Lexicographically smallest first when frequencies are equal.

--------------------------------------------------

Time Complexity: O(n log k)

Where:

- n = total number of words.

Building the frequency map takes O(n).

Each heap insertion/removal takes O(log k).

--------------------------------------------------

Space Complexity: O(n)

- HashMap stores all unique words.
- Heap stores at most k elements.

--------------------------------------------------

Pattern Used:
Hashing + Min Heap (Priority Queue) + Custom Comparator

Key Learning:

1. Custom comparators allow heaps to follow complex ordering rules.
2. A Min Heap efficiently maintains the top k elements without sorting everything.
3. Tie-breaking conditions are often handled inside the comparator rather than after sorting.
4. Reversing the extracted heap elements restores the required descending priority order.
*/

class Solution {
public:

    struct Compare
    {
        bool operator()(pair<int, string>& a, pair<int, string>& b)
        {
            // Smaller frequency has higher priority (min heap)
            if(a.first != b.first)
                return a.first > b.first;

            // If frequencies are equal,
            // lexicographically larger word has higher priority
            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Count word frequencies
        unordered_map<string, int> mp;

        for(string s : words)
        {
            mp[s]++;
        }

        // Step 2: Maintain a Min Heap of size k
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            Compare
        > pq;

        for(auto &p : mp)
        {
            pq.push({p.second, p.first});

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        // Step 3: Extract the answer
        vector<string> ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
