/*
Problem 169. Majority Element

Problem Statement:
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
It is guaranteed that the majority element always exists in the array.

--------------------------------------------------

Intuition:

If an element appears more than n/2 times, then it will outnumber
all other elements combined.

We can think of every occurrence of the majority element as a vote
for itself and every occurrence of a different element as a vote
against it.

Whenever we encounter two different elements, we cancel one occurrence
of each. Since the majority element appears more than n/2 times,
it will still remain after all possible cancellations.

This idea leads to the Boyer-Moore Voting Algorithm.

--------------------------------------------------

Approach:

1. Maintain two variables:
   - ans  -> current candidate for majority element.
   - freq -> vote count of the current candidate.

2. Traverse the array.

3. If freq becomes 0:
   - Select the current element as the new candidate.

4. If the current element matches the candidate:
   - Increase freq.

5. Otherwise:
   - Decrease freq because the current element cancels one vote
     of the candidate.

6. After the traversal, the candidate stored in ans will be
   the majority element.

--------------------------------------------------

Example:

nums = [2,2,1,1,1,2,2]

Candidate = 2, freq = 1
2 -> freq = 2
1 -> freq = 1
1 -> freq = 0
1 -> candidate = 1, freq = 1
2 -> freq = 0
2 -> candidate = 2, freq = 1

Answer = 2

--------------------------------------------------

Why This Works:

The majority element occurs more than n/2 times.

Every non-majority element can cancel at most one occurrence
of the majority element.

Since the majority element has more occurrences than all other
elements combined, it cannot be completely eliminated.

Therefore, the final candidate remaining after all cancellations
must be the majority element.

--------------------------------------------------

Time Complexity: O(n)

We traverse the array exactly once.

--------------------------------------------------

Space Complexity: O(1)

Only two variables are used regardless of input size.

--------------------------------------------------

Pattern Used:
Boyer-Moore Voting Algorithm

Key Learning:
- Useful for finding majority elements.
- Based on vote cancellation.
- Achieves O(n) time and O(1) space.
*/



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // freq stores the current vote count of the candidate
        // ans stores the current candidate for majority element
        int freq = 0, ans = 0;

        // Traverse the entire array
        for(int i = 0; i < nums.size(); i++)
        {
            // If vote count becomes zero,
            // choose the current element as a new candidate
            if(freq == 0)
            { 
                ans = nums[i];
            }

            // If current element matches the candidate,
            // increase its vote count
            if(ans == nums[i])
            {
                freq++;
            }
            else
            {
                // Different element found,
                // cancel one vote of the candidate
                freq--;
            }
        }

        // The remaining candidate is the majority element
        return ans;
    }
};
