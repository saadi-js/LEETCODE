# 🧠 LeetCode Solutions in C++

A curated collection of **160 LeetCode solutions** written in C++ with detailed comments explaining the intuition, approach, time/space complexity, and pattern used for every problem.

> Problems are organized by **pattern / data structure** so you can study by topic and recognize problem-solving patterns during interviews.

---

## 📌 Table of Contents

- [📊 Repository Stats](#-repository-stats)
- [🔁 Two Pointers](#-two-pointers)
- [🪟 Sliding Window](#-sliding-window)
- [🔍 Binary Search](#-binary-search)
- [#️⃣ Hashing](#-hashing)
- [📐 Math & Simulation](#-math--simulation)
- [📋 Arrays](#-arrays)
- [🟦 Matrix](#-matrix)
- [🔗 Linked List](#-linked-list)
- [📚 Stack](#-stack)
- [🌲 Trees (BFS / DFS)](#-trees-bfs--dfs)
- [⛰️ Heap / Priority Queue](#️-heap--priority-queue)
- [🔙 Backtracking](#-backtracking)
- [🚀 Coming Soon](#-coming-soon)

---

## 📊 Repository Stats

| Category | Problems Solved |
|---|---|
| Two Pointers | 14 |
| Sliding Window | 9 |
| Binary Search | 14 |
| Hashing | 17 |
| Math & Simulation | 14 |
| Arrays | 23 |
| Matrix | 2 |
| Linked List | 13 |
| Stack | 15 |
| Trees (BFS / DFS) | 15 |
| Heap / Priority Queue | 7 |
| Backtracking | 4 |
| String Manipulation | 11 |
| **Total** | **160** 🎉 |

---

## 🔁 Two Pointers

The two-pointer technique uses two indices that move through the data structure — typically from both ends toward the middle, or at different speeds — to reduce O(n²) brute force into O(n).

**When to use:** Finding pairs with a target sum, palindrome checking, removing duplicates, partitioning, cycle detection.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 1 | [Two Sum](./1_Two_Sum.cpp) | 🟢 Easy | Complement search with HashMap |
| 11 | [Container With Most Water](./11_Container_With_Most_Water.cpp) | 🟡 Medium | Greedy — move the shorter pointer inward |
| 15 | [3Sum](./15_3Sum.cpp) | 🟡 Medium | Sort + fix one element + two-pointer for the rest |
| 26 | [Remove Duplicates from Sorted Array](./26_Remove_Duplicates_from_Sorted_Array.cpp) | 🟢 Easy | Slow/fast pointer; slow tracks unique boundary |
| 27 | [Remove Element](./27_Remove_Element.cpp) | 🟢 Easy | Write pointer skips the target value |
| 125 | [Valid Palindrome](./125_Valid_Palindrome.cpp) | 🟢 Easy | Skip non-alphanumeric, compare lowercase from both ends |
| 167 | [Two Sum II – Sorted Array](./167_Two_Sum_II_Input_Array_Is_Sorted.cpp) | 🟡 Medium | Sorted array → converging pointers |
| 283 | [Move Zeroes](./283_Move_Zeroes.cpp) | 🟢 Easy | Partition: swap non-zeros forward |
| 392 | [Is Subsequence](./392_Is_Subsequence.cpp) | 🟢 Easy | Greedy match through target string |
| 18 | [4Sum](./18_4Sum.cpp) | 🟡 Medium | Sort + two pointers with duplicate skipping |
| 42 | [Trapping Rain Water](./42_Trapping_Rain_Water.cpp) | 🔴 Hard | Two pointers with left/right max tracking |
| 88 | [Merge Sorted Array](./88_Merge_Sorted_Array.cpp) | 🟢 Easy | Fill from the end with three pointers |
| 977 | [Squares of a Sorted Array](./977_Squares_of_a_Sorted_Array.cpp) | 🟢 Easy | Compare squares from both ends |
| 2540 | [Minimum Common Value](./2540. Minimum Common Value.cpp) | 🟢 Easy | Advance the smaller pointer until values match |

---

## 🪟 Sliding Window

A window that expands/contracts over an array or string. Fixed-size windows reuse prior sums; variable-size windows shrink when a constraint is violated.

**When to use:** Longest/shortest subarray or substring, maximum sum of k elements, at-most-K distinct elements.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 3 | [Longest Substring Without Repeating Characters](./3_Longest_Substring_Without_Repeating_Characters.cpp) | 🟡 Medium | Variable window + frequency map; shrink on duplicate |
| 424 | [Longest Repeating Character Replacement](./424_Longest_Repeating_Character_Replacement.cpp) | 🟡 Medium | Window valid if `(size - maxFreq) ≤ k` |
| 567 | [Permutation in String](./567_Permutation_in_String.cpp) | 🟡 Medium | Fixed window of `|s1|`; compare frequency arrays |
| 643 | [Maximum Average Subarray I](./643_Maximum_Average_Subarray_I.cpp) | 🟢 Easy | Fixed window of size k; slide and update sum |
| 904 | [Fruit Into Baskets](./904_Fruit_Into_Baskets.cpp) | 🟡 Medium | At-most-2-distinct → variable window + HashMap |
| 1004 | [Max Consecutive Ones III](./1004_Max_Consecutive_Ones_III.cpp) | 🟡 Medium | Count zeros in window; shrink when zeros > k |
| 1456 | [Max Vowels in Substring of Length K](./1456_Maximum_Number_of_Vowels_in_a_Substring_of_Given_Length.cpp) | 🟡 Medium | Fixed window; add incoming vowel, remove outgoing |
| 209 | [Minimum Size Subarray Sum](./209_Minimum_Size_Subarray_Sum.cpp) | 🟡 Medium | Shrink window while the sum stays large enough |
| 485 | [Max Consecutive Ones](./485_Max_Consecutive_Ones.cpp) | 🟢 Easy | Count streaks of 1s with a running window |

---

## 🔍 Binary Search

Eliminates half the search space each iteration. Works on sorted arrays and on any **monotonic condition** over an answer space.

**When to use:** Sorted array lookups, rotated arrays, peak finding, "find minimum k such that condition holds".

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 33 | [Search in Rotated Sorted Array](./33_Search_in_Rotated_Sorted_Array.cpp) | 🟡 Medium | Identify which half is sorted, then eliminate |
| 35 | [Search Insert Position](./35_Search_Insert_Position.cpp) | 🟢 Easy | Standard BS; `start` = insertion point when not found |
| 74 | [Search a 2D Matrix](./74_Search_a_2D_Matrix.cpp) | 🟡 Medium | Binary search on rows, then on the row itself |
| 153 | [Find Minimum in Rotated Sorted Array](./153_Find_Minimum_in_Rotated_Sorted_Array.cpp) | 🟡 Medium | Compare `mid` with `end` to find unsorted segment |
| 240 | [Search a 2D Matrix II](./240_Search_a_2D_Matrix_II.cpp) | 🟡 Medium | Start top-right; move down or left to eliminate |
| 441 | [Arranging Coins](./441_Arranging_Coins.cpp) | 🟢 Easy | Binary search on k where `k(k+1)/2 ≤ n` |
| 704 | [Binary Search](./704_Binary_Search.cpp) | 🟢 Easy | Classic binary search template |
| 852 | [Peak Index in Mountain Array](./852_Peak_Index_in_a_Mountain_Array.cpp) | 🟡 Medium | Compare `mid` with `mid+1` to find slope direction |
| 875 | [Koko Eating Bananas](./875_Koko_Eating_Bananas.cpp) | 🟡 Medium | Binary search on answer space `[1, max(piles)]` |
| 34 | [Find First and Last Position of Element in Sorted Array](./34_Find_First_and_Last_Position_of_Element_in_Sorted_Array.cpp) | 🟡 Medium | Binary search twice to find the left and right bounds |
| 69 | [Sqrt(x)](./69_Sqrt_x.cpp) | 🟢 Easy | Binary search the integer square root |
| 162 | [Find Peak Element](./162_Find_Peak_Element.cpp) | 🟡 Medium | Compare `mid` with neighbors to move toward a peak |
| 228 | [Summary Ranges](./228. Summary Ranges.cpp) | 🟢 Easy | Scan consecutive runs and emit intervals |
| 540 | [Single Element in a Sorted Array](./540_Single_Element_in_a_Sorted_Array.cpp) | 🟡 Medium | Pair alignment + binary search on the odd side |

---

## #️⃣ Hashing

Hash maps and hash sets give O(1) average lookups — ideal for counting frequencies, grouping, and complement searches.

**When to use:** Duplicate detection, anagram grouping, frequency counting, uniqueness verification, prefix-sum pair finding.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 49 | [Group Anagrams](./49_Group_Anagrams.cpp) | 🟡 Medium | Sorted string as canonical key in HashMap |
| 128 | [Longest Consecutive Sequence](./128_Longest_Consecutive_Sequence.cpp) | 🟡 Medium | HashSet; only expand from sequence start `(x-1 not in set)` |
| 217 | [Contains Duplicate](./217_Contains_Duplicate.cpp) | 🟢 Easy | Insert into map; duplicate if already present |
| 242 | [Valid Anagram](./242_Valid_Anagram.cpp) | 🟢 Easy | Frequency map of s, then subtract using t |
| 387 | [First Unique Character in a String](./387_First_Unique_Character_in_a_String.cpp) | 🟢 Easy | freq[26] array; two-pass — count then find first with freq 1 |
| 451 | [Sort Characters By Frequency](./451_Sort_Characters_By_Frequency.cpp) | 🟡 Medium | Frequency map + bucket sort by frequency |
| 560 | [Subarray Sum Equals K](./560_Subarray_Sum_Equals_K.cpp) | 🟡 Medium | Prefix sum + HashMap; count `prefixSum - k` occurrences |
| 1207 | [Unique Number of Occurrences](./1207_Unique_Number_of_Occurrences.cpp) | 🟢 Easy | Build freq map; check all frequencies unique via HashSet |
| 2149 | [Rearrange Array Elements by Sign](./2149_Rearrange_Array_Elements_by_Sign.cpp) | 🟡 Medium | Separate even/odd index pointers for positives/negatives |
| 3866 | [First Unique Even Element](./3866_First_Unique_Even_Element.cpp) | 🟢 Easy | Count only evens in map; scan original order for freq == 1 |
| 205 | [Isomorphic Strings](./205_Isomorphic_Strings.cpp) | 🟢 Easy | Track a one-to-one character mapping |
| 219 | [Contains Duplicate II](./219_Contains_Duplicate_II.cpp) | 🟢 Easy | HashMap remembers last index seen for each value |
| 290 | [Word Pattern](./290_Word_Pattern.cpp) | 🟢 Easy | Two-way map between pattern chars and words |
| 349 | [Intersection of Two Arrays](./349. Intersection of Two Arrays.cpp) | 🟢 Easy | Insert into sets, then keep shared values once |
| 350 | [Intersection of Two Arrays II](./350. Intersection of Two Arrays II.cpp) | 🟢 Easy | Count frequencies and consume matches |
| 383 | [Ransom Note](./383. Ransom Note.cpp) | 🟢 Easy | Frequency count the magazine and subtract letters |
| 389 | [Find the Difference](./389. Find the Difference.cpp) | 🟢 Easy | Frequency or XOR to isolate the extra character |

---

## 📐 Math & Simulation

Problems solved through arithmetic reasoning, digit manipulation, or simulating a described process step by step.

**When to use:** Digit problems, power computation, overflow detection, string parsing, carry propagation, combinatorics.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 7 | [Reverse Integer](./7_Reverse_Integer.cpp) | 🟡 Medium | Check overflow BEFORE multiplying: `rev > INT_MAX/10` |
| 8 | [String to Integer (atoi)](./8_String_to_Integer_atoi.cpp) | 🟡 Medium | Four phases: skip spaces → sign → digits → clamp |
| 9 | [Palindrome Number](./9_Palindrome_Number.cpp) | 🟢 Easy | Convert to string; two-pointer palindrome check |
| 50 | [Pow(x, n)](./50_Pow_x_n.cpp) | 🟡 Medium | Binary exponentiation — O(log n) via repeated squaring |
| 66 | [Plus One](./66_Plus_One.cpp) | 🟢 Easy | Carry propagation right-to-left; prepend 1 if all 9s |
| 357 | [Count Numbers With Unique Digits](./357_Count_Numbers_With_Unique_Digits.cpp) | 🟡 Medium | Combinatorics — first digit 9 choices, next 9, 8, 7… |
| 1281 | [Subtract Product and Sum of Digits](./1281_Subtract_the_Product_and_Sum_of_Digits_of_an_Integer.cpp) | 🟢 Easy | `% 10` extracts digit; `/ 10` removes it |
| 1480 | [Running Sum of 1D Array](./1480_Running_Sum_of_1d_Array.cpp) | 🟢 Easy | In-place prefix sum: `nums[i] += nums[i-1]` |
| 136 | [Single Number](./136_Single_Number.cpp) | 🟢 Easy | XOR cancels paired values |
| 191 | [Number of 1 Bits](./191_Number_of_1_Bits.cpp) | 🟢 Easy | Shift or clear the lowest set bit until zero |
| 202 | [Happy Number](./202_Happy_Number.cpp) | 🟢 Easy | Repeated digit-square sums with cycle detection |
| 2235 | [Add Two Integers](./2235. Add Two Integers.cpp) | 🟢 Easy | Direct arithmetic addition |
| 258 | [Add Digits](./258. Add Digits.cpp) | 🟢 Easy | Repeated digit sum or digital-root math |
| 338 | [Counting Bits](./338_Counting_Bits.cpp) | 🟢 Easy | DP / bit parity for every integer from 0 to n |

---

## 📋 Arrays

General array manipulation — sorting tricks, in-place reordering, prefix/suffix products, and greedy scans.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 14 | [Longest Common Prefix](./14_Longest_Common_Prefix.cpp) | 🟢 Easy | Sort; compare only first and last string |
| 53 | [Maximum Subarray](./53_Maximum_Subarray.cpp) | 🟡 Medium | Kadane's — reset running sum when it goes negative |
| 121 | [Best Time to Buy and Sell Stock](./121_Best_Time_to_Buy_and_Sell_Stock.cpp) | 🟢 Easy | Track min price so far; compute profit at each step |
| 169 | [Majority Element](./169_Majority_Element.cpp) | 🟢 Easy | Boyer-Moore voting — cancel non-majority votes |
| 179 | [Largest Number](./179_Largest_Number.cpp) | 🟡 Medium | Custom sort: `a+b > b+a` determines order |
| 189 | [Rotate Array](./189_Rotate_Array.cpp) | 🟡 Medium | Three reversals: whole → first k → last n-k |
| 238 | [Product of Array Except Self](./238_Product_of_Array_Except_Self.cpp) | 🟡 Medium | Prefix product pass + suffix variable in reverse pass |
| 287 | [Find the Duplicate Number](./287_Find_the_Duplicate_Number.cpp) | 🟡 Medium | Floyd's cycle detection on index-value linked list |
| 448 | [Find All Numbers Disappeared in Array](./448_Find_All_Numbers_Disappeared_in_an_Array.cpp) | 🟢 Easy | Mark visited indices negative; positive index = missing |
| 922 | [Sort Array By Parity II](./922_Sort_Array_By_Parity_II.cpp) | 🟢 Easy | Two placement pointers for even and odd indices |
| 41 | [First Missing Positive](./41. First Missing Positive.cpp) | 🔴 Hard | Place each number at its index if possible |
| 54 | [Spiral Matrix](./54_Spiral_Matrix.cpp) | 🟡 Medium | Traverse layer by layer while shrinking boundaries |
| 75 | [Sort Colors](./75. Sort Colors.cpp) | 🟡 Medium | Dutch national flag with low/mid/high pointers |
| 80 | [Remove Duplicates from Sorted Array II](./80_Remove_Duplicates_from_Sorted_Array_II.cpp) | 🟡 Medium | Keep at most two copies with a write pointer |
| 1299 | [Replace Elements with Greatest Element on Right Side](./1299_Replace_Elements_with_Greatest_Element_on_Right_Side.cpp) | 🟢 Easy | Scan from right while tracking the max so far |
| 1431 | [Kids With the Greatest Number of Candies](./1431_Kids_With_the_Greatest_Number_of_Candies.cpp) | 🟢 Easy | Compare each kid against the current max |
| 1929 | [Concatenation of Array](./1929_Concatenation_of_Array.cpp) | 🟢 Easy | Duplicate the array into a 2n result |
| 2150 | [Find All Lonely Numbers in the Array](./2150. Find All Lonely Numbers in the Array.cpp) | 🟢 Easy | Count frequencies and keep isolated values |
| 268 | [Missing Number](./268_Missing_Number.cpp) | 🟢 Easy | Sum or XOR against the expected range total |
| 303 | [Range Sum Query - Immutable](./303. Range Sum Query - Immutable.cpp) | 🟢 Easy | Prefix sums answer range queries in O(1) |
| 347 | [Top K Frequent Elements](./347. Top K Frequent Elements.cpp) | 🟡 Medium | Bucket sort or heap on element frequencies |
| 724 | [Find Pivot Index](./724_Find_Pivot_Index.cpp) | 🟢 Easy | Prefix/suffix balance around each index |
| 905 | [Sort Array By Parity](./905. Sort Array By Parity.cpp) | 🟢 Easy | Partition evens before odds |

---

## 🟦 Matrix

2D grid problems that exploit row/column structure or geometric transformations.

**When to use:** In-place transformations, diagonal traversal, spiral order, row/column sorted search.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 48 | [Rotate Image](./48_Rotate_Image.cpp) | 🟡 Medium | Clockwise 90° = Transpose + Reverse each row |
| 36 | [Valid Sudoku](./36_Valid_Sudoku.cpp) | 🟡 Medium | Three HashSets — one per row, column, and 3×3 box |

---

## 🔗 Linked List

Pointer manipulation problems. Key techniques: dummy nodes, fast/slow pointers, reversal, and merging.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 2 | [Add Two Numbers](./2_Add_Two_Numbers.cpp) | 🟡 Medium | Digit-by-digit addition with carry propagation |
| 19 | [Remove Nth Node From End of List](./19_Remove_Nth_Node_From_End_of_List.cpp) | 🟡 Medium | Fast pointer n steps ahead; slow stops before target |
| 21 | [Merge Two Sorted Lists](./21_Merge_Two_Sorted_Lists.cpp) | 🟢 Easy | Recursive merge-sort style comparison |
| 83 | [Remove Duplicates from Sorted List](./83_Remove_Duplicates_from_Sorted_List.cpp) | 🟢 Easy | Skip duplicate adjacent nodes in one pass |
| 138 | [Copy List with Random Pointer](./138_Copy_List_with_Random_Pointer.cpp) | 🟡 Medium | HashMap: original → clone; two-pass for random pointers |
| 141 | [Linked List Cycle](./141_Linked_List_Cycle.cpp) | 🟢 Easy | Floyd's cycle detection — fast and slow pointers meet |
| 142 | [Linked List Cycle II](./142_Linked_List_Cycle_II.cpp) | 🟡 Medium | After detection, reset slow to head; both advance 1 step |
| 143 | [Reorder List](./143_Reorder_List.cpp) | 🟡 Medium | Find middle → reverse second half → merge alternately |
| 206 | [Reverse Linked List](./206_Reverse_Linked_List.cpp) | 🟢 Easy | Three-pointer iterative reversal |
| 876 | [Middle of the Linked List](./876_Middle_of_the_Linked_List.cpp) | 🟢 Easy | Fast moves 2x; when fast ends, slow is at middle |
| 160 | [Intersection of Two Linked Lists](./160. Intersection of Two Linked Lists.cpp) | 🟢 Easy | Align pointer lengths or switch heads on null |
| 234 | [Palindrome Linked List](./234. Palindrome Linked List.cpp) | 🟢 Easy | Find middle, reverse second half, compare halves |
| 430 | [Flatten a Multilevel Doubly Linked List](./430_Flatten_a_Multilevel_Doubly_Linked_List.cpp) | 🟡 Medium | DFS flatten child lists and relink pointers |

---

## 📚 Stack

LIFO order makes stacks perfect for matching pairs, "undo" operations, next greater/smaller elements, and expression evaluation.

**When to use:** Bracket matching, expression evaluation, monotonic next-greater problems, backspace simulation.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 20 | [Valid Parentheses](./20_Valid_Parentheses.cpp) | 🟢 Easy | Push opening brackets; match and pop on closing |
| 150 | [Evaluate Reverse Polish Notation](./150_Evaluate_Reverse_Polish_Notation.cpp) | 🟡 Medium | Push numbers; on operator pop two, compute, push result |
| 155 | [Min Stack](./155_Min_Stack.cpp) | 🟡 Medium | Store `(value, minSoFar)` pairs — O(1) getMin |
| 496 | [Next Greater Element I](./496_Next_Greater_Element_I.cpp) | 🟢 Easy | Monotonic decreasing stack on nums2; HashMap for O(1) lookup |
| 739 | [Daily Temperatures](./739_Daily_Temperatures.cpp) | 🟡 Medium | Monotonic stack of indices; resolve when warmer found |
| 844 | [Backspace String Compare](./844_Backspace_String_Compare.cpp) | 🟢 Easy | Simulate typing with a stack; '#' pops last character |
| 1047 | [Remove All Adjacent Duplicates In String](./1047_Remove_All_Adjacent_Duplicates_In_String.cpp) | 🟢 Easy | Push char or pop if it matches stack top |
| 2390 | [Removing Stars From a String](./2390_Removing_Stars_From_a_String.cpp) | 🟡 Medium | '*' pops most recent character from stack |
| 84 | [Largest Rectangle in Histogram](./84. Largest Rectangle in Histogram.cpp) | 🔴 Hard | Monotonic increasing stack of bar indices |
| 225 | [Implement Stack using Queues](./225. Implement Stack using Queues.cpp) | 🟢 Easy | Use two queues or one queue rotation |
| 232 | [Implement Queue using Stacks](./232. Implement Queue using Stacks.cpp) | 🟢 Easy | Use two stacks for push and pop transfer |
| 316 | [Remove Duplicate Letters](./316. Remove Duplicate Letters.cpp) | 🟡 Medium | Monotonic stack keeps the smallest lexicographic result |
| 402 | [Remove K Digits](./402_Remove_K_Digits.cpp) | 🟡 Medium | Monotonic stack removes larger digits greedily |
| 682 | [Baseball Game](./682. Baseball Game.cpp) | 🟢 Easy | Stack simulates score history and operators |
| 735 | [Asteroid Collision](./735. Asteroid Collision.cpp) | 🟡 Medium | Stack resolves right-moving vs left-moving asteroids |

---

## 🌲 Trees (BFS / DFS)

Tree problems divide into **DFS** (recursive depth-first, natural for height/path/structure) and **BFS** (queue-based level-order, natural for level views and shortest paths).

### DFS Problems

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 98 | [Validate Binary Search Tree](./98_Validate_Binary_Search_Tree.cpp) | 🟡 Medium | Pass `(min, max)` range bounds down the recursion |
| 100 | [Same Tree](./100_Same_Tree.cpp) | 🟢 Easy | Recurse both trees simultaneously; compare structure + values |
| 104 | [Maximum Depth of Binary Tree](./104_Maximum_Depth_of_Binary_Tree.cpp) | 🟢 Easy | `max(leftDepth, rightDepth) + 1` bottom-up |
| 105 | [Construct Tree from Preorder & Inorder](./105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp) | 🟡 Medium | Preorder gives root; inorder gives left/right boundary |
| 230 | [Kth Smallest Element in a BST](./230_Kth_Smallest_Element_in_a_BST.cpp) | 🟡 Medium | Inorder traversal = sorted order; count to k |
| 236 | [Lowest Common Ancestor](./236_Lowest_Common_Ancestor_of_Binary_Tree.cpp) | 🟡 Medium | Postorder; first node where both sides return non-null |
| 543 | [Diameter of Binary Tree](./543_Diameter_of_Binary_Tree.cpp) | 🟢 Easy | At each node: `leftHeight + rightHeight`; track global max |
| 572 | [Subtree of Another Tree](./572_Subtree_of_Another_Tree.cpp) | 🟢 Easy | Traverse root; at matching values run full equality check |
| 1448 | [Count Good Nodes in Binary Tree](./1448_Count_Good_Nodes_in_Binary_Tree.cpp) | 🟡 Medium | DFS carrying `maxSoFar` on path; node is good if ≥ max |
| 94 | [Binary Tree Inorder Traversal](./94_Binary_Tree_Inorder_Traversal.cpp) | 🟢 Easy | DFS left → node → right |
| 103 | [Binary Tree Zigzag Level Order Traversal](./103. Binary Tree Zigzag Level Order Traversal.cpp) | 🟡 Medium | Level order traversal with alternating direction |
| 111 | [Minimum Depth of Binary Tree](./111. Minimum Depth of Binary Tree.cpp) | 🟢 Easy | DFS / BFS to first leaf |
| 144 | [Binary Tree Preorder Traversal](./144_Binary_Tree_Preorder_Traversal.cpp) | 🟢 Easy | DFS node → left → right |
| 145 | [Binary Tree Postorder Traversal](./145_Binary_Tree_Postorder_Traversal.cpp) | 🟢 Easy | DFS left → right → node |
| 226 | [Invert Binary Tree](./226. Invert Binary Tree.cpp) | 🟢 Easy | Swap left and right children recursively |

### BFS Problems

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 102 | [Binary Tree Level Order Traversal](./102_Binary_Tree_Level_Order_Traversal.cpp) | 🟡 Medium | Queue + snapshot `levelSize` each iteration |
| 199 | [Binary Tree Right Side View](./199_Binary_Tree_Right_Side_View.cpp) | 🟡 Medium | BFS; record last node of each level |

### String Manipulation

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 58 | [Length of Last Word](./58_Length_of_Last_Word.cpp) | 🟢 Easy | Reverse scan: skip trailing spaces, count word characters |
| 151 | [Reverse Words in a String](./151_Reverse_Words_in_a_String.cpp) | 🟡 Medium | Reverse whole string, then reverse each word individually |
| 1910 | [Remove All Occurrences of a Substring](./1910_Remove_All_Occurrences_of_a_Substring.cpp) | 🟡 Medium | Repeatedly `find + erase` until no occurrence remains |
| 28 | [Find the Index of the First Occurrence in a String](./28. Find the Index of the First Occurrence in a String.cpp) | 🟢 Easy | Use string search or a simple scan |
| 71 | [Simplify Path](./71. Simplify Path.cpp) | 🟡 Medium | Stack-like processing of path segments |
| 344 | [Reverse String](./344_Reverse_String.cpp) | 🟢 Easy | Two pointers swap characters in place |
| 415 | [Add Strings](./415. Add Strings.cpp) | 🟢 Easy | Digit-by-digit addition from the end |
| 443 | [String Compression](./443_String_Compression.cpp) | 🟢 Easy | Run-length encode in place with a write pointer |
| 520 | [Detect Capital](./520_Detect_Capital.cpp) | 🟢 Easy | Check capitalization patterns directly |
| 680 | [Valid Palindrome II](./680. Valid Palindrome II.cpp) | 🟢 Easy | Allow one mismatch and test both skips |
| 1662 | [Check If Two String Arrays are Equivalent](./1662_Check_If_Two_String_Arrays_are_Equivalent.cpp) | 🟢 Easy | Compare joined strings lazily with pointers |

---

## ⛰️ Heap / Priority Queue

A max-heap or min-heap gives O(log n) insert/extract and O(1) peek — ideal for top-K problems and greedy scheduling.

**When to use:** Kth largest/smallest, dynamic median, greedy scheduling, sliding window maximum.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 215 | [Kth Largest Element in Array](./215_Kth_Largest_Element_in_an_Array.cpp) | 🟡 Medium | Min-heap of size k; top = kth largest |
| 239 | [Sliding Window Maximum](./239_Sliding_Window_Maximum.cpp) | 🔴 Hard | Max-heap with index; lazily remove out-of-window elements |
| 621 | [Task Scheduler](./621_Task_Scheduler.cpp) | 🟡 Medium | Max-heap; schedule up to `n+1` tasks per cycle greedily |
| 703 | [Kth Largest Element in a Stream](./703_Kth_Largest_Element_in_a_Stream.cpp) | 🟢 Easy | Min-heap of size k maintained on every `add()` call |
| 973 | [K Closest Points to Origin](./973_K_Closest_Points_to_Origin.cpp) | 🟡 Medium | Max-heap of size k by squared distance |
| 1046 | [Last Stone Weight](./1046_Last_Stone_Weight.cpp) | 🟢 Easy | Max-heap; extract two heaviest, push difference if unequal |
| 692 | [Top K Frequent Words](./692. Top K Frequent Words.cpp) | 🟡 Medium | Heap or sorting on word frequencies and lexicographic order |

---

## 🔙 Backtracking

Explore all possibilities through recursive decision trees, undoing choices (backtracking) before trying the next branch.

**When to use:** Permutations, combinations, subsets, constraint satisfaction.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 46 | [Permutations](./46_Permutations.cpp) | 🟡 Medium | Swap-based recursion; fix one element per level |
| 78 | [Subsets](./78_Subsets.cpp) | 🟡 Medium | Binary choice per element — include or exclude |
| 90 | [Subsets II](./90_Subsets_II.cpp) | 🟡 Medium | Sort + skip `nums[i] == nums[i-1]` at same recursion depth |
| 925 | [Long Pressed Name](./925_Long_Pressed_Name.cpp) | 🟢 Easy | Two pointers; allow repeated typed chars if same as previous |

---

## 🚀 Coming Soon

The repository is actively growing. Upcoming sections:

### 🌐 Graphs
- BFS / DFS on graphs
- Union-Find / Disjoint Set
- Topological Sort
- Shortest Path (Dijkstra, BFS)

### 💡 Dynamic Programming
- 1D DP (Climbing Stairs, House Robber, Coin Change)
- 2D DP (Grid paths, Edit Distance, LCS)
- Knapsack variants
- Subsequence problems

### ⚙️ Bit Manipulation
- AND / OR / XOR tricks
- Counting set bits
- Power of 2 checks
- Single Number variants

---

## 📖 How to Read Each File

Every solution file follows a consistent structure:

```
/*
Problem X. Problem Name

Problem Statement:   What the problem asks
Intuition:           Why naive approaches fall short
Key Idea:            The core insight that makes it efficient
Approach:            Step-by-step algorithm
Example:             Walkthrough with a sample input
Why This Works:      Mathematical / logical justification
Time Complexity:     Big-O analysis
Space Complexity:    Memory usage
Pattern Used:        The reusable pattern to recognize
Key Learning:        What to take away for future problems
*/

class Solution { ... };
```

---

## 🎯 Pattern Quick Reference

| Pattern | Complexity | Core Trick | Example Problems |
|---|---|---|---|
| Two Pointers | O(n) | Two indices moving toward each other or at different speeds | 3Sum, Container With Most Water |
| Sliding Window (Fixed) | O(n) | Add new element, remove old, reuse prior sum | Max Vowels, Max Average Subarray |
| Sliding Window (Variable) | O(n) | Shrink from left when constraint violated | Longest Substring, Fruit Into Baskets |
| Binary Search | O(log n) | Eliminate half search space per step | Koko, Peak Index, Rotated Array |
| HashMap / HashSet | O(n) | O(1) lookup for complement or frequency | Two Sum, Group Anagrams, Subarray Sum |
| Frequency Array | O(n) | Fixed size-26 array for character counts | First Unique Char, Valid Anagram |
| Monotonic Stack | O(n) | Stack kept in increasing/decreasing order | Daily Temperatures, Next Greater Element |
| Fast & Slow Pointers | O(n) | Two speeds to find middle or detect cycle | Linked List Cycle, Middle of List |
| Prefix Sum | O(n) | `prefix[j] - prefix[i]` gives range sum | Subarray Sum Equals K, Running Sum |
| Heap (Top-K) | O(n log k) | Keep k best elements using opposite heap | Kth Largest, K Closest Points |
| Backtracking | O(2ⁿ) / O(n!) | Explore + undo choices recursively | Subsets, Permutations |
| Tree DFS | O(n) | Postorder/preorder recursion carrying state | Diameter, LCA, Count Good Nodes |
| Tree BFS | O(n) | Level-by-level queue traversal | Level Order, Right Side View |
| Matrix Transform | O(n²) | Transpose + Reverse = clockwise rotation | Rotate Image |
| Digit Manipulation | O(log n) | `% 10` extracts, `/ 10` removes last digit | Reverse Integer, atoi |

---

## 🛠️ Setup

All solutions are standalone `.cpp` files. To test any solution locally:

```bash
# Compile
g++ -std=c++17 -o solution 1_Two_Sum.cpp

# Or use LeetCode's online judge directly
```

---

## 🤝 Contributing

Feel free to open an issue or pull request if you spot a bug, have a cleaner approach, or want to suggest a problem to add.

---

*Happy coding! Consistency beats intensity — one problem a day keeps the FAANG away. 🚀*
