/*
Problem 155. Min Stack

Problem Statement:
Design a stack that supports push, pop, top, and retrieving the minimum element
in constant time.

You must implement all operations in O(1) time complexity.

Intuition:
A normal stack cannot give minimum in O(1) unless we maintain extra information.

So instead of storing only values, we store additional metadata at each step:
- current value
- minimum value up to that point

Key Idea:
Each stack element stores a pair:
(value, current_min_so_far)

So at any point:
- top() gives current value
- getMin() gives minimum so far instantly

Approach:
1. Use a stack of pairs: (value, min_so_far)
2. For push:
   - If stack is empty → min is value itself
   - Else → min(value, previous_min)
3. For pop:
   - Remove top element
4. For top:
   - Return first of pair
5. For getMin:
   - Return second of pair

Example:
Push: [5, 3, 7, 2]

Stack:
(5,5)
(3,3)
(7,3)
(2,2)

Why This Works:
We precompute and store the minimum at every level of the stack.
So no traversal is needed during getMin().

Time Complexity:
- push: O(1)
- pop: O(1)
- top: O(1)
- getMin: O(1)

Space Complexity: O(n)

Pattern Used:
Stack with Auxiliary State Storage

Key Learning:
Whenever you need constant-time min/max tracking in a stack:
→ store extra state at each level
*/



class MinStack {
public:

    // Stack stores pair: (value, minimum up to this point)
    stack<pair<int, int>> st;

    MinStack() {
        // Constructor (no initialization needed)
    }

    void push(int value) {

        // If stack is empty, value is also the minimum
        if(st.empty())
        {
            st.push({value, value});
        }
        else
        {
            // Compute minimum between new value and previous minimum
            int mini = min(value, st.top().second);

            // Push value with updated minimum
            st.push({value, mini});
        }
    }

    void pop() {
        // Remove top element
        st.pop();
    }

    int top() {
        // Return actual stored value
        return st.top().first;
    }

    int getMin() {
        // Return minimum stored at current stack level
        return st.top().second;
    }
};
