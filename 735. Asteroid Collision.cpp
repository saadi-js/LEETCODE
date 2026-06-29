/*
Problem 735. Asteroid Collision

Problem Statement:

We are given an array asteroids representing asteroids moving in a line.

- A positive value means the asteroid is moving to the right.
- A negative value means the asteroid is moving to the left.
- The absolute value represents the asteroid's size.

When two asteroids moving in opposite directions collide:

- The smaller asteroid explodes.
- If both are the same size, both explode.
- Asteroids moving in the same direction never collide.

Return the state of the asteroids after all collisions.

--------------------------------------------------

Intuition:

An asteroid can only collide when:

- A previous asteroid is moving right (positive), and
- The current asteroid is moving left (negative).

This means we only need to compare the current asteroid with the most
recent right-moving asteroid.

A stack is perfect because it always keeps track of the latest asteroid
that could potentially collide.

--------------------------------------------------

Key Idea:

Step 1: Traverse every asteroid.
Step 2: While the current asteroid can collide with the top of the stack:
        - If the current asteroid is larger, destroy the top asteroid.
        - If both are equal, destroy both.
        - If the top asteroid is larger, destroy the current asteroid.
Step 3: If the current asteroid survives every collision,
        push it onto the stack.
Step 4: The remaining stack represents the final state.

--------------------------------------------------

Approach:

1. Create an empty stack.
2. Traverse every asteroid.
3. A collision is possible only when:
   - Stack is not empty.
   - Stack top is positive.
   - Current asteroid is negative.
4. Handle collisions:
   - |current| > top:
       Pop the top asteroid and continue checking.
   - |current| == top:
       Pop the top asteroid.
       Destroy the current asteroid.
   - |current| < top:
       Destroy the current asteroid.
5. If the current asteroid survives,
   push it onto the stack.
6. Extract the stack into a vector and reverse it.
7. Return the final vector.

--------------------------------------------------

Example:

Input:

asteroids = [5,10,-5]

Process:

5

Stack:
[5]

------------------

10

Stack:
[5,10]

------------------

-5

Collision with 10

|5| < 10

-5 is destroyed.

Stack:
[5,10]

Output:

[5,10]

--------------------------------------------------

Another Example:

Input:

asteroids = [8,-8]

Process:

8

Stack:
[8]

-8

Same size

Both explode.

Stack:
[]

Output:

[]

--------------------------------------------------

Counter Example:

Input:

asteroids = [10,2,-5]

Process:

10

Stack:
[10]

2

Stack:
[10,2]

-5

Collides with 2

2 explodes

Stack:
[10]

Now collides with 10

10 survives

Final Stack:

[10]

Output:

[10]

--------------------------------------------------

Why This Works:

The stack always stores asteroids that have survived so far.

A collision is only possible between:

- A right-moving asteroid already in the stack.
- A left-moving asteroid currently being processed.

The while loop continues until either:

- The current asteroid is destroyed.
- The stack becomes safe.
- The current asteroid survives all collisions.

Thus, every possible collision is resolved exactly once.

--------------------------------------------------

Time Complexity: O(n)

Although there is a nested while loop, each asteroid is pushed onto
the stack at most once and popped at most once.

Overall complexity is O(n).

--------------------------------------------------

Space Complexity: O(n)

In the worst case, no collisions occur and every asteroid is stored
in the stack.

--------------------------------------------------

Pattern Used:
Stack / Simulation

Key Learning:

1. A stack naturally models problems where only the most recent element
   can interact with the current one.
2. Nested while loops do not always imply O(n²); here, every asteroid
   is pushed and popped at most once.
3. Carefully identify the exact condition under which a collision can
   occur before simulating interactions.
4. Simulation combined with the correct data structure often leads to
   clean and efficient solutions.
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int ast : asteroids)
        {
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && ast < 0)
            {
                if(abs(ast) > st.top())
                {
                    st.pop();
                }
                else if(abs(ast) == st.top())
                {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else
                {
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed)
            {
                st.push(ast);
            }
        }

        vector<int> ans;

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
