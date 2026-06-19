/*
Problem 739. Daily Temperatures

Problem Statement:
Given an array of integers temperatures representing daily temperatures,
return an array answer such that answer[i] is the number of days you have to wait
after the ith day to get a warmer temperature.

If there is no future day for which this is possible, set answer[i] = 0.

Intuition:
For each day, we need to find the next greater element to the right.

Brute force would check all future days for each index → O(n²).

Optimized Idea:
Use a monotonic decreasing stack that stores indices of temperatures.

The stack maintains indices of days whose next warmer day is not yet found.

When we encounter a warmer temperature:
- We resolve all previous days that are smaller than current temperature.

Key Idea:
Maintain a stack of indices such that:
temperatures[stack.top()] is in decreasing order.

When current temperature is higher:
→ It becomes the "next warmer day" for stack elements.

Approach:
1. Create a stack to store indices.
2. Create answer array initialized with 0.
3. Iterate through temperatures:
   a. While stack not empty AND current temperature > stack top temperature:
        - Pop index
        - Compute difference i - idx
        - Store in answer[idx]
   b. Push current index onto stack
4. Return answer array.

Example:
temperatures = [73,74,75,71,69,72,76,73]

Output:
[1,1,4,2,1,1,0,0]

Why This Works:
Each index is pushed and popped at most once.
We only resolve answers when we find the next greater temperature.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern Used:
Monotonic Stack (Next Greater Element)

Key Learning:
Whenever you need "next greater/smaller element":
→ Use monotonic stack (increasing or decreasing)
*/



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // Monotonic stack storing indices
        stack<int> st;

        int n = temperatures.size();

        // Result array initialized with 0 (default if no warmer day exists)
        vector<int> ans(n, 0);

        // Traverse all temperatures
        for(int i = 0; i < n; i++)
        {
            // Resolve all previous days with lower temperature
            while(!st.empty() &&
                  temperatures[i] > temperatures[st.top()])
            {
                // Index of colder day
                int idx = st.top();
                st.pop();

                // Distance to next warmer day
                ans[idx] = i - idx;
            }

            // Push current day index
            st.push(i);
        }

        return ans;
    }
};
