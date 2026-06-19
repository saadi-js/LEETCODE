/*
Problem 239. Sliding Window Maximum

Problem Statement:
Given an array nums and an integer k, return the maximum value in each sliding window of size k.

Intuition:
For every window of size k, we need the maximum element efficiently.

A brute force approach checks each window → O(nk), which is too slow.

Key Idea:
Use a max-heap (priority queue) to store elements along with their indices.

We keep the heap valid by removing elements that are outside the current window.

At each step:
- Push current element into heap
- Remove elements that are out of window bounds
- The top of heap is the maximum for current window

Approach:
1. Use a max heap of pairs: (value, index).
2. Iterate through nums:
   a. Push (nums[i], i) into heap.
   b. Compute left boundary of window = i - k + 1.
   c. Remove elements whose index < left (out of window).
   d. If window is valid (i >= k - 1), store heap top.
3. Return result array.

Example:
nums = [1,3,-1,-3,5,3,6,7], k = 3

Windows:
[1,3,-1] → 3
[3,-1,-3] → 3
[-1,-3,5] → 5
...

Why This Works:
Heap always maintains candidates for maximum,
and outdated elements are lazily removed when they fall outside the window.

Time Complexity: O(n log n)
Space Complexity: O(n)

Pattern Used:
Heap (Priority Queue) + Sliding Window + Lazy Deletion

Key Learning:
When you need "maximum in a moving window":
→ Use deque (optimal) or heap (simpler but slower)
*/



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // Max heap storing (value, index)
        priority_queue<pair<int, int>> pq;

        // Stores result of each window maximum
        vector<int> ans;

        // Traverse the array
        for(int i = 0; i < nums.size(); i++)
        {
            // Push current element with its index
            pq.push({nums[i], i});

            // Left boundary of current window
            int left = i - k + 1;

            // Remove elements outside the window
            while(!pq.empty() && pq.top().second < left)
            {
                pq.pop();
            }

            // If window size reached, record maximum
            if(i >= k - 1)
            {
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};
