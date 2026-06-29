/*
Problem 232. Implement Queue using Stacks

Problem Statement:

Implement a First-In-First-Out (FIFO) queue using only two stacks.

The implemented queue should support the following operations:

- push(x): Insert an element at the back of the queue.
- pop(): Remove and return the element from the front.
- peek(): Return the front element.
- empty(): Return true if the queue is empty.

--------------------------------------------------

Intuition:

A queue follows FIFO (First-In-First-Out), while a stack follows
LIFO (Last-In-First-Out).

A single stack cannot directly behave like a queue because the newest
element is always removed first.

Using two stacks solves this problem:

- Input Stack:
  Stores newly inserted elements.

- Output Stack:
  Stores elements in queue order so that the oldest element is on top.

Whenever the output stack becomes empty, we move every element from the
input stack to the output stack. This reverses their order, making the
oldest inserted element appear on top.

--------------------------------------------------

Key Idea:

Step 1: Push every new element into the input stack.
Step 2: When pop() or peek() is called:
        - If the output stack is empty,
          transfer all elements from input to output.
Step 3: Perform pop() or peek() on the output stack.
Step 4: The queue is empty only if both stacks are empty.

--------------------------------------------------

Approach:

1. Maintain two stacks:
   - input
   - output
2. push(x):
   - Push x into the input stack.
3. pop():
   - If output is empty:
       Move every element from input to output.
   - Pop and return the top of output.
4. peek():
   - If output is empty:
       Transfer all elements from input.
   - Return the top of output.
5. empty():
   - Return true only if both stacks are empty.

--------------------------------------------------

Example:

Operations:

push(1)
push(2)
peek()
pop()
empty()

Process:

push(1)

Input:
[1]

Output:
[]

------------------

push(2)

Input:
[1,2]

Output:
[]

------------------

peek()

Transfer:

Input:
[]

Output:
[2,1]

Front = 1

------------------

pop()

Remove 1

Output:
[2]

Return:
1

------------------

empty()

Input:
[]

Output:
[2]

Queue is not empty.

Output:
false

--------------------------------------------------

Counter Example:

Operations:

push(5)
pop()

Transfer:

Input:
[5]

↓

Output:
[5]

Pop:

Return:
5

Both stacks become empty.

empty() → true

--------------------------------------------------

Why This Works:

The input stack stores elements in insertion order.

When elements are transferred to the output stack, their order is
reversed.

The oldest inserted element becomes the top of the output stack,
allowing FIFO behavior.

Each element is moved from input to output at most once, making the
implementation efficient.

--------------------------------------------------

Time Complexity:

push(): O(1)

pop(): O(1) amortized

peek(): O(1) amortized

empty(): O(1)

Although transferring elements takes O(n), every element is transferred
only once, giving an amortized O(1) complexity.

--------------------------------------------------

Space Complexity: O(n)

Both stacks together store at most n elements.

--------------------------------------------------

Pattern Used:
Stack / Queue Simulation / Amortized Analysis

Key Learning:

1. Two stacks can efficiently simulate a queue.
2. Reverse order by transferring elements from one stack to another.
3. Expensive transfers happen only when necessary, leading to amortized O(1) operations.
4. Amortized analysis considers the average cost across many operations rather than a single worst-case operation.
*/

class MyQueue {
public:

    stack<int> input;
    stack<int> output;

    MyQueue() {

    }

    void push(int x) {
        input.push(x);
    }

    int pop() {

        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        int front = output.top();
        output.pop();

        return front;
    }

    int peek() {

        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
