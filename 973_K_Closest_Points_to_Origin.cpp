/*
Problem 973. K Closest Points to Origin

Problem Statement:
Given an array of points where points[i] = [xi, yi],
return the k closest points to the origin (0,0).

Distance is defined as:
    sqrt(x^2 + y^2)
But we avoid sqrt since comparison is unaffected:
    use x^2 + y^2

Intuition:
We need the k smallest distances efficiently.
Instead of sorting all points (O(n log n)),
we maintain a max-heap of size k.

Key Idea:
- Use a max-heap to store k closest points seen so far
- If a new point is closer than the farthest in heap → replace it

Approach:
1. For each point:
   - compute squared distance
   - push into max heap (distance, point)
2. If heap size exceeds k:
   - remove farthest point (top of max heap)
3. Remaining heap contains k closest points
4. Extract results

Example:

points = [[1,3],[-2,2]], k = 1

Distances:
(1,3) → 10
(-2,2) → 8

Result: (-2,2)

Why This Works:
We always maintain only k best candidates.

Time Complexity: O(n log k)
Space Complexity: O(k)

Pattern Used:
Heap / Top-K Selection

Key Learning:
When asked for “k smallest/largest elements in a stream”,
use a heap of size k instead of sorting everything.
*/




class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // Max heap storing (distance, point)
        priority_queue<pair<int, vector<int>>> pq;

        vector<vector<int>> ans;

        for(auto &p : points)
        {
            int x = p[0];
            int y = p[1];

            // Squared distance from origin
            int distance = x*x + y*y;

            // Push into max heap
            pq.push({distance, p});

            // Maintain only k closest points
            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        // Extract remaining k points
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
