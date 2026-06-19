/*
Problem 904. Fruit Into Baskets

Problem Statement:
You are given an array fruits where fruits[i] represents the type of fruit at tree i.
You have two baskets, and each basket can only hold one type of fruit.

You can start at any index and pick fruits moving to the right.
You must collect fruits continuously, but you can only carry at most 2 distinct fruit types.

Return the maximum number of fruits you can collect.

Intuition:
This is a classic "longest substring/subarray with at most K distinct elements" problem,
where K = 2.

We want the longest contiguous segment containing at most 2 unique fruit types.

Instead of restarting for every segment, we use a sliding window that expands to the right
and shrinks from the left whenever constraint is violated.

Key Idea:
Use a variable-size sliding window + frequency map.

Maintain:
- A window [left, right]
- A frequency map of fruit types in the window
- Ensure map size ≤ 2 at all times

Whenever the window contains more than 2 fruit types:
- Shrink from the left until constraint is satisfied again.

Approach:
1. Use unordered_map to store frequency of fruit types in current window.
2. Expand right pointer and include fruits[right].
3. If more than 2 distinct types exist:
   - Move left pointer forward
   - Decrease frequency of fruits[left]
   - Remove fruit type if frequency becomes 0
4. After each step, compute window size = right - left + 1
5. Track maximum window size.

Example:
fruits = [1,2,1,2,3]

Step-by-step:
[1,2,1,2] → valid (2 types)
[2,1,2,3] → invalid (3 types), shrink window

Max valid window = 4

Why This Works:
The window always represents the longest valid segment ending at 'right'
that contains at most 2 distinct fruit types.

By shrinking only when invalid, we ensure every element is processed at most twice.

Time Complexity: O(n)
Space Complexity: O(1) (at most 3 keys temporarily, effectively constant)

Pattern Used:
Variable Size Sliding Window + Frequency Map (At Most K Distinct)

Key Learning:
Whenever a problem asks for:
→ "Longest subarray with at most K distinct elements"
→ "Maximum window under constraints"

Think:
Sliding Window + HashMap
*/



class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // Map to store frequency of each fruit type in current window
        unordered_map<int,int> count;

        // Left pointer of sliding window
        int left = 0;

        // Stores the maximum number of fruits collected
        int maxFruits = 0;

        // Expand window using right pointer
        for(int right = 0; right < fruits.size(); right++)
        {
            // Include current fruit in window
            count[fruits[right]]++;

            // If we have more than 2 distinct fruit types, shrink window
            while(count.size() > 2)
            {
                // Remove fruit at left pointer from window
                count[fruits[left]]--;

                // If frequency becomes 0, remove it from map
                if(count[fruits[left]] == 0)
                {
                    count.erase(fruits[left]);
                }

                // Move left pointer forward
                left++;
            }

            // Update maximum window size
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};
