/*
Problem 560. Subarray Sum Equals K

Problem Statement:

Given an integer array nums and an integer k,
return the total number of continuous subarrays whose sum equals k.

--------------------------------------------------

Intuition:

A brute force approach would be:

- Try every possible subarray
- Compute its sum
- Check if it equals k

This takes O(n²) or O(n³) depending on implementation.

We need an optimized approach.

--------------------------------------------------

Key Idea:

We use Prefix Sum + Hash Map.

Observation:

Let prefix_sum[j] = sum of elements from index 0 to j.

Then sum of subarray (i+1 to j) is:

prefix_sum[j] - prefix_sum[i] = k

Rearranging:

prefix_sum[i] = prefix_sum[j] - k

So for every index j, we need to find how many previous prefix sums
equal (prefix_sum[j] - k).

--------------------------------------------------

Approach:

1. Maintain prefix sum while traversing the array.
2. Use a hash map to store frequency of prefix sums.
3. For each index:
   - Compute current prefix sum
   - Check if (prefix_sum - k) exists in map
   - If yes, add its frequency to answer
4. Also handle case where prefix_sum itself equals k
   (subarray starting from index 0)

--------------------------------------------------

Example:

nums = [1,2,3], k = 3

Prefix sums:
[1,3,6]

Valid subarrays:
[1,2] → 3
[3]   → 3

Answer = 2

--------------------------------------------------

Why This Works:

We convert a subarray sum problem into:

Finding pairs of prefix sums with a fixed difference (k).

This reduces checking all subarrays into O(n).

--------------------------------------------------

Time Complexity: O(n)

Each element is processed once.

Hash map operations are O(1) average.

--------------------------------------------------

Space Complexity: O(n)

In worst case, we store all prefix sums.

--------------------------------------------------

Pattern Used:
Prefix Sum + Hash Map

Key Learning:

1. Subarray problems → think prefix sum.
2. "Count number of subarrays" → think frequency map.
3. Convert range sum into difference of prefix sums.
4. Very common pattern in array + hashing problems.
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // size of the array
        int n = nums.size();

        // counter for valid subarrays
        int count = 0;

        // prefix_sum[i] stores sum from 0 to i
        vector<int> prefix_sum(n, 0);

        // initialize first prefix sum
        prefix_sum[0] = nums[0];

        // build prefix sum array
        for(int i = 1; i < n; i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        // hashmap to store frequency of prefix sums
        unordered_map<int, int> m;

        // iterate through all prefix sums
        for(int j = 0; j < n; j++)
        {
            // case 1: subarray from 0 to j equals k
            if(prefix_sum[j] == k)
            {
                count++;
            }

            // required prefix sum to form sum k
            int val = prefix_sum[j] - k;

            // if such prefix sum exists, add its frequency
            if(m.find(val) != m.end())
            {
                count += m[val];
            }

            // insert current prefix sum into map
            if(m.find(prefix_sum[j]) == m.end())
            {
                m[prefix_sum[j]] = 0;
            }

            // increment frequency of current prefix sum
            m[prefix_sum[j]]++;
        }

        // return total count of subarrays
        return count;
    }
};
