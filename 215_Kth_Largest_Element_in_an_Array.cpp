/*
Problem 215. Kth Largest Element in an Array

Problem Statement:
Given an integer array nums and an integer k,
return the kth largest element in the array.

Note: It is the kth largest in sorted order, not distinct.

Intuition:
We need to efficiently track the k largest elements while iterating.
Instead of sorting the full array (O(n log n)),
we maintain a min-heap of size k.

Key Idea:
- Min-heap stores the k largest elements seen so far
- The smallest among them (heap top) is the kth largest overall

Approach:
1. Create a min-heap
2. Iterate through nums:
   - push element into heap
   - if heap size exceeds k → pop smallest
3. After processing all elements:
   - heap top is kth largest

Example:

nums = [3,2,1,5,6,4], k = 2

Heap evolution:
3 → [3]
2 → [2,3]
1 → [1,2,3] → pop 1 → [2,3]
5 → [2,3,5] → pop 2 → [3,5]
6 → [3,5,6] → pop 3 → [5,6]
4 → [4,5,6] → pop 4 → [5,6]

Answer = 5

Why This Works:
We never store more than k elements,
ensuring efficient tracking of top k values.

Time Complexity: O(n log k)
Space Complexity: O(k)

Pattern Used:
Heap / Top-K Elements

Key Learning:
To find kth largest efficiently in streaming or unsorted data,
use a min-heap of size k.
*/




class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {

        // Min-heap to store k largest elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // Process all numbers
        for(int num : nums)
        {
            pq.push(num);

            // Maintain heap size = k
            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        // Top is kth largest element
        return pq.top();
    }
};
