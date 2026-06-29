/*
Problem 349. Intersection of Two Arrays

Problem Statement:

Given two integer arrays nums1 and nums2, return an array containing
their intersection.

Each element in the result must be unique, and the order of the output
does not matter.

--------------------------------------------------

Intuition:

We need to find the elements that appear in both arrays, but each common
element should appear only once in the answer.

A brute-force approach would compare every element of nums1 with every
element of nums2, resulting in O(n × m) time.

Instead, we can store all elements of the first array in a HashSet.
Then, while traversing the second array, we can quickly check whether
an element exists in the first array.

To avoid duplicates in the answer, we remove an element from the set
immediately after adding it to the result.

--------------------------------------------------

Key Idea:

Step 1: Insert all elements of nums1 into a HashSet.
Step 2: Traverse nums2.
Step 3: If the current element exists in the HashSet:
        - Add it to the answer.
        - Remove it from the set so it cannot be added again.
Step 4: Return the answer.

--------------------------------------------------

Approach:

1. Create an unordered_set containing all elements of nums1.
2. Create an empty answer vector.
3. Traverse nums2.
4. For each element:
   - Check whether it exists in the set.
   - If it does:
     - Add it to the answer.
     - Erase it from the set to prevent duplicates.
5. Return the answer vector.

--------------------------------------------------

Example:

Input:

nums1 = [1,2,2,1]
nums2 = [2,2]

HashSet:
{1,2}

Traversal:

2 exists
→ Add 2
→ Remove 2 from set

Second 2
→ No longer exists in set

Output:
[2]

--------------------------------------------------

Counter Example:

Input:

nums1 = [1,2,3]
nums2 = [4,5,6]

HashSet:
{1,2,3}

No element from nums2 exists in the set.

Output:
[]

--------------------------------------------------

Why This Works:

The HashSet provides O(1) average lookup time.

Removing an element immediately after adding it to the answer ensures
that every common element is included exactly once, satisfying the
problem's uniqueness requirement.

--------------------------------------------------

Time Complexity: O(n + m)

Where:
- n = size of nums1
- m = size of nums2

Building the set takes O(n), and traversing nums2 takes O(m).

--------------------------------------------------

Space Complexity: O(n)

The HashSet stores all unique elements of nums1.

--------------------------------------------------

Pattern Used:
Hashing / HashSet

Key Learning:

1. HashSets provide fast membership checking in O(1) average time.
2. Erasing an element after processing is an elegant way to avoid duplicates.
3. Preprocessing one array into a set eliminates the need for nested loops.
4. Hashing is a common technique for solving intersection and lookup problems efficiently.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> ans;

        for(int x : nums2)
        {
            if(st.find(x) != st.end())
            {
                ans.push_back(x);
                st.erase(x);
            }
        }

        return ans;
    }
};
