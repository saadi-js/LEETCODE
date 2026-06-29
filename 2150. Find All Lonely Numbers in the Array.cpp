/*
Problem 2150. Find All Lonely Numbers in the Array

Problem Statement:

Given an integer array nums, return all lonely numbers in the array.

A number is considered lonely if:
1. It appears exactly once in the array.
2. Neither its previous value (x - 1) nor its next value (x + 1) exists in the array.

The order of the returned numbers does not matter.

--------------------------------------------------

Intuition:

To determine whether a number is lonely, we need to answer three questions:

1. How many times does the number appear?
2. Does the previous number (x - 1) exist?
3. Does the next number (x + 1) exist?

A brute-force solution would check every element against every other element,
resulting in O(n²) time.

Instead, we can store the frequency of every number in a hash map.
Then each of the three conditions can be checked in O(1) average time.

--------------------------------------------------

Key Idea:

Step 1: Count the frequency of every number using a HashMap.
Step 2: Traverse the original array.
Step 3: A number is lonely only if:
        - Its frequency is exactly 1.
        - (x - 1) is not present.
        - (x + 1) is not present.
Step 4: Add such numbers to the answer.

--------------------------------------------------

Approach:

1. Create an unordered_map to store the frequency of every element.
2. Traverse the array and populate the frequency map.
3. Traverse the array again.
4. For every element:
   - Check if its frequency is 1.
   - Check whether x - 1 is absent.
   - Check whether x + 1 is absent.
5. If all three conditions are satisfied, add the number to the answer.
6. Return the answer vector.

--------------------------------------------------

Example:

nums = [10,6,5,8]

Frequency Map:
10 → 1
6  → 1
5  → 1
8  → 1

Checking each number:

10:
Frequency = 1
9 not present
11 not present
→ Lonely

6:
Frequency = 1
5 exists
→ Not lonely

5:
Frequency = 1
6 exists
→ Not lonely

8:
Frequency = 1
7 not present
9 not present
→ Lonely

Output:
[10,8]

--------------------------------------------------

Counter Example:

nums = [1,3,3,5]

Frequency Map:
1 → 1
3 → 2
5 → 1

Checking:

1:
Frequency = 1
0 absent
2 absent
→ Lonely

3:
Frequency = 2
→ Not lonely

5:
Frequency = 1
4 absent
6 absent
→ Lonely

Output:
[1,5]

--------------------------------------------------

Why This Works:

The frequency map stores both:
- How many times each value occurs.
- Whether a neighboring value exists.

Since hash map lookup is O(1) on average, every required condition can be
verified efficiently without scanning the array again.

--------------------------------------------------

Time Complexity: O(n)

One pass to build the frequency map.
One pass to identify lonely numbers.

--------------------------------------------------

Space Complexity: O(n)

The hash map stores the frequency of each unique element.

--------------------------------------------------

Pattern Used:
Hashing / Frequency Counting

Key Learning:

1. Hash maps can be used both for frequency counting and fast existence checks.
2. Multiple conditions can often be verified in constant time after preprocessing.
3. Separating preprocessing (frequency counting) from validation leads to clean and efficient solutions.
*/

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ans;

        // Step 1: Count frequency of every number
        for(int x : nums)
        {
            freq[x]++;
        }

        // Step 2: Check loneliness conditions
        for(int i = 0; i < nums.size(); i++)
        {
            if(freq[nums[i]] == 1 &&
               freq.find(nums[i] + 1) == freq.end() &&
               freq.find(nums[i] - 1) == freq.end())
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
