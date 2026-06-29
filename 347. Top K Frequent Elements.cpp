/*
Problem 347. Top K Frequent Elements

Problem Statement:

Given an integer array nums and an integer k, return the k most
frequent elements.

You may return the answer in any order.

--------------------------------------------------

Intuition:

First, we need to know how many times each number appears.

A HashMap efficiently counts frequencies.

Now, instead of sorting all frequencies (which would take O(n log n)),
we maintain only the k most frequent elements using a Min Heap.

The heap always stores the current top k frequent elements.

Whenever its size exceeds k, we remove the element with the smallest
frequency.

--------------------------------------------------

Key Idea:

Step 1: Count the frequency of every number.
Step 2: Store (frequency, number) pairs in a Min Heap.
Step 3: If the heap size becomes greater than k,
        remove the smallest frequency.
Step 4: After processing every number, the heap contains exactly
        the k most frequent elements.
Step 5: Extract the numbers from the heap.

--------------------------------------------------

Approach:

1. Create a HashMap to count frequencies.
2. Traverse the array and build the frequency map.
3. Create a Min Heap storing:
      (frequency, value)
4. Traverse the frequency map:
   - Push every pair into the heap.
   - If heap size exceeds k, remove the smallest frequency.
5. Pop every element from the heap and store the values.
6. Return the answer.

--------------------------------------------------

Example:

Input:

nums = [1,1,1,2,2,3]
k = 2

Frequency Map:

1 → 3
2 → 2
3 → 1

Heap Process:

Push (3,1)

Heap:
[(3,1)]

------------------

Push (2,2)

Heap:
[(2,2),(3,1)]

------------------

Push (1,3)

Heap size becomes 3

Remove smallest frequency:

(1,3)

Remaining Heap:

[(2,2),(3,1)]

Output:

[2,1]

(The order does not matter.)

--------------------------------------------------

Counter Example:

Input:

nums = [5]
k = 1

Frequency:

5 → 1

Heap:

[(1,5)]

Output:

[5]

--------------------------------------------------

Why This Works:

The Min Heap always keeps the least frequent element among the current
top k elements at its root.

Whenever a new element is inserted:

- If it is more frequent than the heap's minimum,
  it replaces the least frequent element.
- Otherwise, it is discarded.

Thus, after processing every unique number, only the k most frequent
elements remain.

--------------------------------------------------

Time Complexity: O(n log k)

- Building the frequency map: O(n)
- Heap operations for each unique element: O(log k)

This is more efficient than sorting all frequencies when k is much
smaller than n.

--------------------------------------------------

Space Complexity: O(n)

- HashMap stores frequencies.
- Heap stores at most k elements.

--------------------------------------------------

Pattern Used:
Hashing + Min Heap (Priority Queue)

Key Learning:

1. HashMaps efficiently count frequencies.
2. A Min Heap is ideal when maintaining the top k largest elements.
3. Instead of sorting all elements, keep only k candidates in the heap.
4. Whenever the heap exceeds size k, remove the smallest frequency to
   preserve only the most frequent elements.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequencies
        unordered_map<int, int> mp;

        for(int x : nums)
        {
            mp[x]++;
        }

        // Step 2: Maintain a Min Heap of size k
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
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
        vector<int> ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
