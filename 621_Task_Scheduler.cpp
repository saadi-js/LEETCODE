/*
Problem 621. Task Scheduler

Problem Statement:
You are given an array of tasks represented by characters and a cooldown period n.
Each task takes 1 unit of time to execute.
The same task must be separated by at least n intervals.

Return the minimum time required to finish all tasks.

Intuition:
We always want to execute the most frequent tasks first to avoid idle time.
This is a greedy scheduling problem optimized using a max-heap.

Key Idea:
- Always pick up to (n + 1) most frequent tasks in each cycle
- After executing, decrease their frequency
- Reinsert remaining tasks back into heap

This simulates CPU scheduling in chunks.

Approach:
1. Count frequency of each task
2. Push frequencies into max-heap
3. While heap not empty:
   - take up to (n + 1) tasks from heap
   - execute them (decrement frequency)
   - push back remaining tasks
   - add time:
       * if heap empty → add only actual executed tasks
       * else → add full cycle (n + 1)

Why n + 1?
Because in worst case, we fill a block:
A _ _ _ ... A (n gaps between same task)

Example:

tasks = ["A","A","A","B","B","B"], n = 2

Schedule:
A B idle
A B idle
A B

Total = 8

Why This Works:
Greedy ensures highest frequency tasks are spaced out optimally.

Time Complexity: O(N log k)
Space Complexity: O(k)

Pattern Used:
Greedy + Heap + Scheduling

Key Learning:
When tasks have cooldown constraints, think in terms of frequency + heap scheduling cycles.
*/



class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count frequency of each task
        unordered_map<char, int> freq;
        for(char task : tasks)
        {
            freq[task]++;
        }

        // Step 2: Max heap for frequencies
        priority_queue<int> maxHeap;
        for(auto &it : freq)
        {
            maxHeap.push(it.second);
        }

        int time = 0;

        // Step 3: Process tasks in cycles
        while(!maxHeap.empty())
        {
            vector<int> temp;

            // Take up to n+1 tasks per cycle
            for(int i = 0; i < n + 1; i++)
            {
                if(!maxHeap.empty())
                {
                    temp.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }

            // Reduce frequency and push back remaining tasks
            for(int count : temp)
            {
                count--;
                if(count > 0)
                {
                    maxHeap.push(count);
                }
            }

            // If no tasks left → add only executed tasks
            if(maxHeap.empty())
            {
                time += temp.size();
            }
            else
            {
                time += (n + 1);
            }
        }

        return time;
    }
};
