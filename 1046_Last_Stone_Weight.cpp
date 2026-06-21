/*
Problem 1046. Last Stone Weight

Problem Statement:
You are given an array of stones where each stone has a weight.
Each turn, you pick the two heaviest stones:
- If they are equal → both are destroyed
- If not → the smaller is destroyed, and the larger becomes (y - x)

Return the weight of the last remaining stone, or 0 if none.

Intuition:
We always need the two largest stones efficiently.
This is a classic use case for a max-heap.

Key Idea:
Use a priority queue (max-heap) to always access the two largest stones.

Approach:
1. Insert all stones into a max heap
2. While heap has more than 1 stone:
   - extract top two largest stones (y and x)
   - if y != x → push (y - x)
3. Return remaining stone or 0

Example:

stones = [2,7,4,1,8,1]

Step:
8 vs 7 → 1
4 vs 2 → 2
2 vs 1 → 1
1 vs 1 → removed

Final result: 1

Why This Works:
Greedy choice of largest stones ensures correct simulation of process.

Time Complexity: O(n log n)
Space Complexity: O(n)

Pattern Used:
Heap / Greedy Simulation

Key Learning:
Whenever you repeatedly need max/min element dynamically → use heap.
*/



class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {

        // Max heap to always get largest stones
        priority_queue<int> pq;

        // Insert all stones into heap
        for(int stone : stones)
        {
            pq.push(stone);
        }

        // Process until at most one stone remains
        while(pq.size() > 1)
        {
            // Largest stone
            int y = pq.top();
            pq.pop();

            // Second largest stone
            int x = pq.top();
            pq.pop();

            // If they are not equal, push difference
            if(x != y)
            {
                pq.push(y - x);
            }
        }

        // Return last stone or 0
        return pq.empty() ? 0 : pq.top();
    }
};
