/*
Problem 682. Baseball Game

Problem Statement:

You are given a list of operations representing scores in a baseball game.

Each operation can be:

- An integer x:
  Record a new score of x.
- "+":
  Record a new score that is the sum of the previous two valid scores.
- "D":
  Record a new score that is double the previous valid score.
- "C":
  Remove the previous valid score.

Return the sum of all valid scores after performing every operation.

--------------------------------------------------

Intuition:

Each operation depends only on the most recent valid scores.

A stack is the perfect data structure because:

- The latest score is always on the top.
- We can easily remove the last score using pop().
- We can access the previous score using top().
- New valid scores are simply pushed onto the stack.

--------------------------------------------------

Key Idea:

Step 1: Process every operation one by one.
Step 2: Maintain a stack containing all valid scores.
Step 3: Handle each operation:
        - Integer → Push onto the stack.
        - "C" → Remove the last valid score.
        - "D" → Push double the previous score.
        - "+" → Push the sum of the previous two scores.
Step 4: After all operations, sum every score remaining in the stack.

--------------------------------------------------

Approach:

1. Create an empty stack.
2. Traverse every operation.
3. For each operation:
   - If it is "C":
     - Remove the top score.
   - If it is "D":
     - Push twice the top score.
   - If it is "+":
     - Pop the top score temporarily.
     - Read the second top score.
     - Restore the first score.
     - Push the sum of the last two scores.
   - Otherwise:
     - Convert the string into an integer using stoi().
     - Push it onto the stack.
4. Traverse the stack and compute the total score.
5. Return the final sum.

--------------------------------------------------

Example:

Input:

operations = ["5","2","C","D","+"]

Process:

"5"
Stack: [5]

"2"
Stack: [5,2]

"C"
Remove 2

Stack: [5]

"D"
Double previous score

Stack: [5,10]

"+"
5 + 10 = 15

Stack: [5,10,15]

Final Sum:

5 + 10 + 15 = 30

Output:
30

--------------------------------------------------

Counter Example:

Input:

operations = ["5","-2","4","C","D","9","+","+"]

Process:

5
-2
4
Remove 4
Double -2 → -4
Add 9
9 + (-4) = 5
5 + 9 = 14

Stack:

[5,-2,-4,9,5,14]

Sum:

27

Output:
27

--------------------------------------------------

Why This Works:

The stack always stores the current valid scores.

Every operation modifies only the most recent scores:

- "C" removes the latest score.
- "D" duplicates the latest score.
- "+" uses the latest two scores.

Since the stack preserves insertion order and provides efficient access
to the most recent elements, it naturally models the problem.

--------------------------------------------------

Time Complexity: O(n)

Each operation is processed once, and the stack is traversed once to
compute the final sum.

--------------------------------------------------

Space Complexity: O(n)

In the worst case, every operation adds a score to the stack.

--------------------------------------------------

Pattern Used:
Stack / Simulation

Key Learning:

1. Stacks are ideal when operations involve the most recently added elements.
2. Temporarily popping and restoring the top element allows access to the second top without losing data.
3. Simulation problems often become straightforward once the correct data structure is chosen.
4. `stoi()` is useful for converting numeric strings into integers during processing.
*/

class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> st;

        for(string ops : operations)
        {
            if(ops == "C")
            {
                st.pop();
            }
            else if(ops == "D")
            {
                st.push(2 * st.top());
            }
            else if(ops == "+")
            {
                int first = st.top();
                st.pop();

                int second = st.top();

                st.push(first);
                st.push(first + second);
            }
            else
            {
                st.push(stoi(ops));
            }
        }

        int sum = 0;

        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};
