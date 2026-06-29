/*
Problem 71. Simplify Path

Problem Statement:

Given a string path representing an absolute path in a Unix-style file
system, simplify it and return its canonical path.

The canonical path should follow these rules:

- It always starts with a single '/'.
- Multiple consecutive '/' are treated as one.
- '.' represents the current directory and should be ignored.
- '..' represents the parent directory and moves one level up.
- Going above the root directory is not allowed.
- The path should not end with a trailing '/' unless it is the root.

--------------------------------------------------

Intuition:

A Unix path behaves like navigating through folders.

As we process each directory name:

- A normal folder means we enter that directory.
- "." means stay in the current directory.
- ".." means move back to the parent directory.
- Multiple '/' simply separate folder names.

A stack naturally models this behavior because:

- Entering a folder → Push onto the stack.
- Moving to the parent folder → Pop from the stack.

--------------------------------------------------

Key Idea:

Step 1: Parse the path one folder at a time.
Step 2: Ignore empty folder names caused by repeated '/'.
Step 3: Ignore "." since it represents the current directory.
Step 4: For "..":
        - Pop from the stack if possible.
Step 5: Otherwise:
        - Push the folder name.
Step 6: Build the simplified path from the remaining folders.

--------------------------------------------------

Approach:

1. Append an extra '/' to process the last folder.
2. Traverse every character in the path.
3. Build the current folder name until '/' is encountered.
4. When '/' is found:
   - Ignore empty folder names.
   - Ignore ".".
   - Pop the stack for ".." if it is not empty.
   - Otherwise, push the folder name.
5. Extract all folders from the stack.
6. Reverse them because stacks store them in reverse order.
7. Join the folders with '/'.
8. If no folders remain, return "/".

--------------------------------------------------

Example:

Input:

path = "/home//foo/"

Process:

Folder: home

Stack:

[home]

------------------

Repeated '/'

Ignored

------------------

Folder: foo

Stack:

[home, foo]

Result:

"/home/foo"

Output:

"/home/foo"

--------------------------------------------------

Another Example:

Input:

path = "/a/./b/../../c/"

Process:

a

Stack:
[a]

"."

Ignored

b

Stack:
[a,b]

".."

Pop b

Stack:
[a]

".."

Pop a

Stack:
[]

c

Stack:
[c]

Result:

"/c"

Output:

"/c"

--------------------------------------------------

Why This Works:

The stack always represents the current directory hierarchy.

- Entering a directory pushes it onto the stack.
- Going to the parent removes the most recently entered directory.
- Ignoring "." and repeated '/' follows Unix path rules.

After processing every folder, the stack contains exactly the canonical
directory structure.

--------------------------------------------------

Time Complexity: O(n)

Each character of the path is processed exactly once.

--------------------------------------------------

Space Complexity: O(n)

In the worst case, every directory name is stored in the stack.

--------------------------------------------------

Pattern Used:
Stack / String Parsing / Simulation

Key Learning:

1. Stacks are ideal for problems involving "undo" or moving back one step.
2. Parsing strings character by character is often simpler than repeatedly splitting them.
3. Appending a delimiter at the end helps process the final token without special cases.
4. Simulation problems become straightforward once the appropriate data structure is identified.
*/

class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        string folder = "";

        // Add an extra '/' to process the last folder
        path += "/";

        for(char ch : path)
        {
            if(ch == '/')
            {
                if(folder == "")
                {
                    continue;
                }

                if(folder == ".")
                {
                    // Stay in the current directory
                }
                else if(folder == "..")
                {
                    if(!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                {
                    st.push(folder);
                }

                folder = "";
            }
            else
            {
                folder += ch;
            }
        }

        vector<string> dirs;

        while(!st.empty())
        {
            dirs.push_back(st.top());
            st.pop();
        }

        reverse(dirs.begin(), dirs.end());

        string ans = "";

        for(string dir : dirs)
        {
            ans += "/" + dir;
        }

        if(ans == "")
            return "/";

        return ans;
    }
};
