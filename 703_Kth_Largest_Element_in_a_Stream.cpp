/*
Problem 703. Kth Largest Element in a Stream

Problem Statement:
Design a class to find the kth largest element in a stream of numbers.
The class should support:
- Initialization with an integer k and an integer array nums
- add(val): inserts val into the stream and returns the kth largest element

Intuition:
We need to efficiently maintain the kth largest element as numbers arrive.
Instead of sorting the entire stream repeatedly, we maintain only the
k largest elements seen so far.

Key Idea:
Use a min-heap (priority queue) of size k:
- Heap stores the k largest elements
- The smallest among them (heap top) is the kth largest overall

Approach:
1. Maintain a min-heap pq
2. On initialization:
   - Insert all elements using add()
3. On add(val):
   - Push val into heap
   - If heap size exceeds k → remove smallest element
4. Return pq.top() (kth largest element)

Example:

k = 3
stream = [4, 5, 8, 2]

Heap evolution:
4 → [4]
5 → [4,5]
8 → [4,5,8]
2 → [4,5,8] (2 removed)

Now add(10):
→ [5,8,10]
kth largest = 5

Why This Works:
We only keep the k largest elements at any time,
so the smallest in this group is the kth largest overall.

Time Complexity:
- add(): O(log k)
- initialization: O(n log k)

Space Complexity: O(k)

Pattern Used:
Heap / Top-K Elements

Key Learning:
Whenever you need kth largest/smallest in dynamic data,
use a heap of size k instead of sorting entire data.
*/



class KthLargest {
public:

    // Min-heap to store k largest elements
    priority_queue<int, vector<int>, greater<int>> pq;

    // Value of k
    int k;

    KthLargest(int k, vector<int>& nums) {

        // Store k
        this->k = k;

        // Initialize heap with given numbers
        for(int x : nums)
        {
            add(x);
        }
    }

    int add(int val) {

        // Insert new value into heap
        pq.push(val);

        // If heap size exceeds k, remove smallest element
        if(pq.size() > k)
        {
            pq.pop();
        }

        // Top of min-heap is kth largest element
        return pq.top();
    }
};
