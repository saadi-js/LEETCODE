/*
Problem 875. Koko Eating Bananas

Problem Statement:
Koko has n piles of bananas. She can eat at a speed of k bananas per hour.
Each hour, she chooses a pile and eats up to k bananas from it.
If the pile has fewer than k bananas, she finishes it in that hour.

Given an integer array piles and an integer h (hours available),
find the minimum eating speed k such that she can finish all bananas within h hours.

Intuition:
We need to find the minimum k such that a condition is satisfied.
As k increases, required hours decrease monotonically.

This is a classic:
→ Binary Search on Answer

Key Idea:
1. Define search space for k:
   - minimum = 1
   - maximum = max(piles)
2. For each k, compute hours needed
3. If hours <= h → try smaller k
4. Else → increase k

Approach:
1. Set left = 1, right = max pile size
2. While left < right:
   - mid = possible eating speed
   - compute hours needed:
     hr += ceil(pile / mid)
   - if hr <= h → shrink right
   - else → increase left
3. Return minimum valid k

Example:

piles = [3,6,7,11], h = 8

Try k = 4:
hours = 1 + 2 + 2 + 3 = 8 → valid

Try smaller k:
k = 3 → hours > 8 → invalid

Answer = 4

Why This Works:
The function "hours needed" is monotonic:
- smaller k → more hours
- larger k → fewer hours

So binary search guarantees optimal k.

Time Complexity: O(n log max(piles))
Space Complexity: O(1)

Pattern Used:
Binary Search on Answer / Monotonic Function

Key Learning:
Whenever a condition is monotonic over an answer space,
use binary search instead of linear search.
*/




class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {

        // Minimum possible speed
        int left = 1;

        // Maximum possible speed (eat all in one hour from largest pile)
        int right = *max_element(piles.begin(), piles.end());

        // Binary search on answer space
        while(left < right)
        {
            // Mid = current eating speed
            int mid = left + (right - left) / 2;

            // Total hours needed at speed mid
            int hrspent = 0;

            for(int pile : piles)
            {
                // ceil(pile / mid)
                hrspent += pile / mid + (pile % mid != 0);
            }

            // If Koko can finish within h hours
            if(hrspent <= h)
            {
                // Try smaller speed
                right = mid;
            }
            else
            {
                // Need faster speed
                left = mid + 1;
            }
        }

        // Left == right is minimum valid speed
        return right;
    }
};
