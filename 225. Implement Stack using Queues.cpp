/*
Problem 225. Implement Stack using Queues

Problem Statement:

Implement a Last-In-First-Out (LIFO) stack using only a single queue.

The implemented stack should support the following operations:

- push(x): Push an element onto the stack.
- pop(): Remove and return the top element.
- top(): Return the top element.
- empty(): Return true if the stack is empty.

Only standard queue operations are allowed.

--------------------------------------------------

Intuition:

A queue naturally follows FIFO (First-In-First-Out), while a stack
requires LIFO (Last-In-First-Out).

To make a queue behave like a stack, we ensure that after every push,
the newly inserted element is moved to the front of the queue.

This way:

- The newest element always stays at the front.
- pop() and top() become simple front operations.

--------------------------------------------------

Key Idea:

Step 1: Insert the new element at the back of the queue.
Step 2: Rotate the queue by moving the previous elements
        from the front to the back.
Step 3: After rotation, the newly inserted element becomes
        the front of the queue.
Step 4: Now front() always represents the stack's top.

--------------------------------------------------

Approach:

1. Maintain a single queue.
2. push(x):
   - Push x into the queue.
   - Let n be the queue size.
   - Rotate the first n-1 elements to the back.
3. pop():
   - Remove and return the front element.
4. top():
   - Return the front element.
5. empty():
   - Return whether the queue is empty.

--------------------------------------------------

Example:

Operations:

push(1)
push(2)
top()
pop()
empty()

Process:

Initially:

Queue:
[]

------------------

push(1)

Queue:
[1]

------------------

push(2)

Insert:

[1,2]

Rotate once:

[2,1]

Top is now 2.

------------------

top()

Return:
2

------------------

pop()

Remove front:

Queue:
[1]

Return:
2

------------------

empty()

Queue is not empty.

Output:
false

--------------------------------------------------

Counter Example:

Operations:

push(5)
pop()
empty()

Process:

Queue:

[5]

Pop:

Queue:
[]

Return:
5

Now the queue is empty.

Output:
true

--------------------------------------------------

Why This Works:

Every time a new element is inserted, rotating the queue places it
at the front.

Since the newest element is always at the front, removing from the
front behaves exactly like popping from the top of a stack.

Thus, a single queue successfully simulates LIFO behavior.

--------------------------------------------------

Time Complexity:

push(): O(n)

The rotation may move n-1 elements.

pop(): O(1)

top(): O(1)

empty(): O(1)

--------------------------------------------------

Space Complexity: O(n)

The queue stores all stack elements.

--------------------------------------------------

Pattern Used:
Queue / Stack Simulation

Key Learning:

1. Data structures can often simulate one another with clever manipulation.
2. Rotating a queue after insertion places the newest element at the front.
3. Choosing where to spend extra time (push vs pop) leads to different implementations.
4. This solution makes push() expensive so that pop() and top() remain constant time.
*/

class MyStack {
public:

    queue<int> q;

    MyStack() {

    }

    void push(int x) {

        q.push(x);

        int n = q.size();

        for(int i = 0; i < n - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {

        int front = q.front();
        q.pop();

        return front;
    }

    int top() {

        return q.front();
    }

    bool empty() {

        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
