/*
Problem 350. Intersection of Two Arrays II

Problem Statement:

Given two integer arrays nums1 and nums2, return an array containing
their intersection.

Each element in the result should appear as many times as it appears
in both arrays. The order of the output does not matter.

--------------------------------------------------

Intuition:

Unlike the previous intersection problem, duplicates are allowed in
the answer.

For example:

nums1 = [1,2,2,1]
nums2 = [2,2]

The answer should be [2,2] because 2 appears twice in both arrays.

To keep track of how many copies of each number are still available,
we store the frequency of every element from nums1 in a HashMap.

Then, while traversing nums2, if a number still has a positive frequency,
we add it to the answer and decrease its frequency.

--------------------------------------------------

Key Idea:

Step 1: Count the frequency of every element in nums1.
Step 2: Traverse nums2.
Step 3: If the current number has a remaining frequency:
        - Add it to the answer.
        - Decrease its frequency.
Step 4: Return the answer.

--------------------------------------------------

Approach:

1. Create an unordered_map to store frequencies of elements in nums1.
2. Traverse nums1 and increment the frequency of each number.
3. Create an empty answer vector.
4. Traverse nums2.
5. For each element:
   - If its frequency is greater than zero:
     - Add it to the answer.
     - Decrement its frequency.
6. Return the answer.

--------------------------------------------------

Example:

Input:

nums1 = [4,9,5]
nums2 = [9,4,9,8,4]

Frequency Map:

4 → 1
9 → 1
5 → 1

Traversal of nums2:

9
Frequency = 1
Add 9
Decrease frequency to 0

4
Frequency = 1
Add 4
Decrease frequency to 0

9
Frequency = 0
Skip

8
Not present
Skip

4
Frequency = 0
Skip

Output:
[9,4]

--------------------------------------------------

Counter Example:

Input:

nums1 = [1,2,2,1]
nums2 = [2]

Frequency Map:

1 → 2
2 → 2

Traversal:

2
Frequency = 2
Add 2
Decrease frequency to 1

Output:
[2]

Only one 2 is included because nums2 contains only one occurrence.

--------------------------------------------------

Why This Works:

The frequency map stores how many unused occurrences of each element
are still available from nums1.

Whenever we find a matching element in nums2, we consume one occurrence
by decrementing its frequency.

This guarantees that every element appears in the answer exactly
min(freq in nums1, freq in nums2) times.

--------------------------------------------------

Time Complexity: O(n + m)

Where:
- n = size of nums1
- m = size of nums2

Each array is traversed exactly once.

--------------------------------------------------

Space Complexity: O(n)

The HashMap stores the frequency of each unique element in nums1.

--------------------------------------------------

Pattern Used:
Hashing / Frequency Counting

Key Learning:

1. Frequency maps are useful when duplicate elements must be handled.
2. Decrementing the frequency after using an element prevents adding it
   more times than it appears.
3. HashMaps provide O(1) average lookup and update operations.
4. This pattern is commonly used in problems involving counting and matching occurrences.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mp;
        vector<int> ans;

        // Step 1: Count the frequency of elements in nums1
        for(int x : nums1)
        {
            mp[x]++;
        }

        // Step 2: Find common elements
        for(int i = 0; i < nums2.size(); i++)
        {
            if(mp[nums2[i]] > 0)
            {
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }

        return ans;
    }
};
