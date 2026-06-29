/*
Problem 84. Largest Rectangle in Histogram

Problem Statement:

Given an array of integers heights representing the heights of bars in a
histogram, where the width of every bar is 1, return the area of the
largest rectangle that can be formed within the histogram.

--------------------------------------------------

Intuition:

Every bar can serve as the height of a rectangle.

To maximize the rectangle for a particular bar, we need to know:

1. How far can we extend to the left before encountering a smaller bar?
2. How far can we extend to the right before encountering a smaller bar?

Once these boundaries are known, the rectangle using the current bar as
its height is:

Area = Height × Width

A monotonic increasing stack efficiently finds the nearest smaller
element on both sides for every bar.

--------------------------------------------------

Key Idea:

Step 1: Find the index of the first smaller element on the right.
Step 2: Find the index of the first smaller element on the left.
Step 3: Compute:

        Width = RightSmaller - LeftSmaller - 1

Step 4: Compute the rectangle area using every bar as the limiting height.
Step 5: Return the maximum area.

--------------------------------------------------

Approach:

1. Traverse from right to left:
   - Maintain an increasing stack.
   - Find the nearest smaller element on the right.
2. Clear the stack.
3. Traverse from left to right:
   - Again maintain an increasing stack.
   - Find the nearest smaller element on the left.
4. For every index:
   - Calculate width.
   - Compute area.
   - Update the maximum answer.
5. Return the largest area.

--------------------------------------------------

Example:

Input:

heights = [2,1,5,6,2,3]

Nearest Smaller to Left:

[-1,-1,1,2,1,4]

Nearest Smaller to Right:

[1,6,4,4,6,6]

For bar 5:

Height = 5

Width = 4 - 1 - 1 = 2

Area = 5 × 2 = 10

This is the maximum rectangle.

Output:

10

--------------------------------------------------

Counter Example:

Input:

heights = [2,4]

For bar 2:

Width = 2

Area = 4

For bar 4:

Width = 1

Area = 4

Output:

4

--------------------------------------------------

Why This Works:

For every bar, the nearest smaller bars on both sides determine the
widest possible rectangle that can use that bar as its height.

The monotonic stack efficiently computes these boundaries in linear time.

Since every bar is considered exactly once as the limiting height,
the maximum rectangle is guaranteed to be found.

--------------------------------------------------

Time Complexity: O(n)

Each index is pushed onto and popped from the stack at most once while
finding the left and right boundaries.

Overall complexity is O(n).

--------------------------------------------------

Space Complexity: O(n)

Two arrays store the left and right boundaries, and the stack stores
indices.

--------------------------------------------------

Pattern Used:
Monotonic Increasing Stack / Nearest Smaller Element

Key Learning:

1. Many histogram problems reduce to finding the nearest smaller element
   on both sides.
2. A monotonic increasing stack computes nearest smaller elements in O(n).
3. Once the boundaries are known, width is:

       right - left - 1

4. Treat every bar as the limiting height of a rectangle instead of
   trying every possible rectangle.
*/





class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int>st;

        //Right smallest
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
            {
                st.pop();
            }
             right[i]=st.empty()? n:st.top();
             st.push(i); 
        }
        while(!st.empty())
        {
            st.pop();
        }

        //left smallest
         for(int i=0;i<n;i++)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
            {
                st.pop();
            }
             left[i]=st.empty()? -1:st.top();
             st.push(i); 
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
           
            int width=right[i]-left[i]-1;
            int currarea=heights[i]*width;
            ans=max(currarea,ans);
        }
        return ans;
    }
};
