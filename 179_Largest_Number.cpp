/*
Problem 179. Largest Number

Problem Statement:
Given a list of non-negative integers, arrange them such that they form
the largest possible number and return it as a string.

Intuition:
The key insight is that normal numeric sorting does not work.
We need to decide order based on concatenation impact:

For two numbers a and b:
- a should come before b if (a+b > b+a)

This ensures the resulting concatenation is maximized.

Key Idea:
Convert comparison into string concatenation ordering rule:
    sort by (s1 + s2) > (s2 + s1)

Approach:
1. Convert numbers into custom sorting rule
2. Sort array using comparator:
   - compare a and b by a+b vs b+a
3. Edge case:
   - if largest element is 0 → return "0"
4. Concatenate all numbers into result string

Example:

nums = [3, 30, 34, 5, 9]

Compare:
9 + 5 > 5 + 9 → 9 first
5 + 34 > 34 + 5 → 5 before 34
30 + 3 < 3 + 30 → 3 before 30

Final order:
[9, 5, 34, 3, 30]

Result:
"9534330"

Why This Works:
We are not comparing values, but their contribution to final string.
Concatenation order determines lexicographically largest result.

Time Complexity: O(n log n)
Space Complexity: O(n)

Pattern Used:
Custom Sorting / Greedy / String Comparator

Key Learning:
When ordering affects final concatenated result,
compare using (a+b vs b+a), not numeric value.
*/




class Solution {
public:

    // Custom comparator for sorting numbers
    static bool helper(int n, int m)
    {
        // Convert integers to strings
        string s1 = to_string(n);
        string s2 = to_string(m);

        // Decide order based on which concatenation is larger
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int>& nums) {

        // Sort using custom comparator
        sort(nums.begin(), nums.end(), helper);

        // Edge case: all zeros
        if(nums[0] == 0) return "0";

        // Build result string
        string result = "";

        for(int num : nums)
        {
            result += to_string(num);
        }

        return result;
    }
};
