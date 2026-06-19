/*
Problem 150. Evaluate Reverse Polish Notation

Problem Statement:
Evaluate the value of an arithmetic expression in Reverse Polish Notation (RPN).

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Division between two integers should truncate toward zero.

Intuition:
RPN eliminates the need for parentheses because order is already defined.

We process tokens left to right and use a stack to store operands.

When we encounter an operator:
- We apply it to the top two elements in correct order
- Push the result back into the stack

Key Idea:
Use a stack to store numbers.
When an operator appears:
- Pop second operand first (a)
- Pop first operand next (b)
- Compute b op a (order matters)
- Push result back

Approach:
1. Initialize an empty stack.
2. Traverse all tokens:
   a. If token is a number → push to stack
   b. If token is an operator:
      - Pop top two elements
      - Apply operation
      - Push result back
3. Final stack element is the result.

Example:
tokens = ["2","1","+","3","*"]

Step-by-step:
2 → push
1 → push
+ → 3
3 → push
* → 9

Result = 9

Why This Works:
RPN guarantees that operands appear before their operator,
so stack naturally resolves dependencies in correct order.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern Used:
Stack (Expression Evaluation)

Key Learning:
Whenever expression is postfix (RPN):
→ Use stack and evaluate left to right
*/



class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        // Stack to store operands
        stack<int> st;

        // Process each token
        for(string &t : tokens)
        {
            // If token is an operator
            if(t == "+" || t == "-" || t == "*" || t == "/")
            {
                // Pop top two operands (order matters)
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                // Apply operation based on operator
                if(t == "+")
                    st.push(b + a);
                else if(t == "-")
                    st.push(b - a);
                else if(t == "*")
                    st.push(b * a);
                else
                    st.push(b / a); // integer division truncates toward zero
            }
            else
            {
                // Convert string to integer and push
                st.push(stoi(t));
            }
        }

        // Final result
        return st.top();
    }
};
