# 🧠 LeetCode Solutions in C++

A curated collection of **94+ LeetCode solutions** written in C++ with detailed comments explaining the intuition, approach, time/space complexity, and pattern used for every problem.

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
| Two Pointers | 9 |
| Sliding Window | 7 |
| Binary Search | 8 |
| Hashing | 8 |
| Math & Simulation | 6 |
| Arrays | 10 |
| Linked List | 11 |
| Stack | 8 |
| Trees (BFS / DFS) | 14 |
| Heap / Priority Queue | 6 |
| Backtracking | 4 |
| **Total** | **94** |

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

---

## #️⃣ Hashing

Hash maps and hash sets give O(1) average lookups — ideal for counting frequencies, grouping, and complement searches.

**When to use:** Duplicate detection, anagram grouping, frequency counting, prefix-sum pair finding.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 49 | [Group Anagrams](./49_Group_Anagrams.cpp) | 🟡 Medium | Sorted string as canonical key in HashMap |
| 128 | [Longest Consecutive Sequence](./128_Longest_Consecutive_Sequence.cpp) | 🟡 Medium | HashSet; only expand from sequence start `(x-1 not in set)` |
| 217 | [Contains Duplicate](./217_Contains_Duplicate.cpp) | 🟢 Easy | Insert into map; duplicate if already present |
| 242 | [Valid Anagram](./242_Valid_Anagram.cpp) | 🟢 Easy | Frequency map of s, then subtract using t |
| 451 | [Sort Characters By Frequency](./451_Sort_Characters_By_Frequency.cpp) | 🟡 Medium | Frequency map + bucket sort by frequency |
| 560 | [Subarray Sum Equals K](./560_Subarray_Sum_Equals_K.cpp) | 🟡 Medium | Prefix sum + HashMap; count `prefixSum - k` occurrences |
| 1281 | [Subtract Product and Sum of Digits](./1281_Subtract_the_Product_and_Sum_of_Digits_of_an_Integer.cpp) | 🟢 Easy | Digit extraction with `% 10` and `/ 10` |
| 2149 | [Rearrange Array Elements by Sign](./2149_Rearrange_Array_Elements_by_Sign.cpp) | 🟡 Medium | Separate even/odd index pointers for positives/negatives |

---

## 📐 Math & Simulation

Problems solved through arithmetic reasoning, digit manipulation, or simulating a described process.

**When to use:** Digit problems, power computation, staircase/combinatorics counting, carry propagation.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 9 | [Palindrome Number](./9_Palindrome_Number.cpp) | 🟢 Easy | Convert to string; two-pointer palindrome check |
| 50 | [Pow(x, n)](./50_Pow_x_n.cpp) | 🟡 Medium | Binary exponentiation — O(log n) via repeated squaring |
| 66 | [Plus One](./66_Plus_One.cpp) | 🟢 Easy | Carry propagation right-to-left; prepend 1 if all 9s |
| 357 | [Count Numbers With Unique Digits](./357_Count_Numbers_With_Unique_Digits.cpp) | 🟡 Medium | Combinatorics — first digit 9 choices, next 9, 8, 7… |
| 1281 | [Subtract Product and Sum of Digits](./1281_Subtract_the_Product_and_Sum_of_Digits_of_an_Integer.cpp) | 🟢 Easy | `% 10` extracts digit; `/ 10` removes it |
| 1480 | [Running Sum of 1D Array](./1480_Running_Sum_of_1d_Array.cpp) | 🟢 Easy | In-place prefix sum: `nums[i] += nums[i-1]` |

---

## 📋 Arrays

General array manipulation — sorting tricks, in-place reordering, prefix/suffix products, and greedy scans.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 14 | [Longest Common Prefix](./14_Longest_Common_Prefix.cpp) | 🟢 Easy | Sort; compare only first and last string |
| 53 | [Maximum Subarray](./53_Maximum_Subarray.cpp) | 🟡 Medium | Kadane's algorithm — reset running sum when negative |
| 121 | [Best Time to Buy and Sell Stock](./121_Best_Time_to_Buy_and_Sell_Stock.cpp) | 🟢 Easy | Track min price so far; compute profit at each step |
| 169 | [Majority Element](./169_Majority_Element.cpp) | 🟢 Easy | Boyer-Moore voting — cancel non-majority votes |
| 179 | [Largest Number](./179_Largest_Number.cpp) | 🟡 Medium | Custom sort: `a+b > b+a` determines order |
| 189 | [Rotate Array](./189_Rotate_Array.cpp) | 🟡 Medium | Three reversals: whole → first k → last n-k |
| 238 | [Product of Array Except Self](./238_Product_of_Array_Except_Self.cpp) | 🟡 Medium | Prefix product pass + suffix variable in one reverse pass |
| 287 | [Find the Duplicate Number](./287_Find_the_Duplicate_Number.cpp) | 🟡 Medium | Floyd's cycle detection on index-value linked list |
| 448 | [Find All Numbers Disappeared in Array](./448_Find_All_Numbers_Disappeared_in_an_Array.cpp) | 🟢 Easy | Mark visited indices negative; positive index = missing |
| 922 | [Sort Array By Parity II](./922_Sort_Array_By_Parity_II.cpp) | 🟢 Easy | Two placement pointers for even and odd indices |

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
| 287 | [Find the Duplicate Number](./287_Find_the_Duplicate_Number.cpp) | 🟡 Medium | Array as linked list; Floyd's cycle gives duplicate |
| 876 | [Middle of the Linked List](./876_Middle_of_the_Linked_List.cpp) | 🟢 Easy | Fast moves 2x; when fast ends, slow is at middle |

---

## 📚 Stack

LIFO order makes stacks perfect for problems involving matching pairs, "undo" operations, next greater/smaller elements, and expression evaluation.

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

---

## 🌲 Trees (BFS / DFS)

Tree problems divide into **DFS** (recursive depth-first, natural for height/path/structure) and **BFS** (queue-based level-order, natural for level views and shortest paths).

### DFS Problems

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 98 | [Validate Binary Search Tree](./98_Validate_Binary_Search_Tree.cpp) | 🟡 Medium | Pass `(min, max)` range bounds down the recursion |
| 100 | [Same Tree](./100_Same_Tree.cpp) | 🟢 Easy | Recurse both trees simultaneously; compare structure + values |
| 104 | [Maximum Depth of Binary Tree](./104_Maximum_Depth_of_Binary_Tree.cpp) | 🟢 Easy | `max(leftDepth, rightDepth) + 1` bottom-up |
| 105 | [Construct Tree from Preorder & Inorder](./105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp) | 🟡 Medium | Preorder gives root; inorder gives left/right split |
| 230 | [Kth Smallest Element in a BST](./230_Kth_Smallest_Element_in_a_BST.cpp) | 🟡 Medium | Inorder traversal = sorted order; count to k |
| 236 | [Lowest Common Ancestor](./236_Lowest_Common_Ancestor_of_Binary_Tree.cpp) | 🟡 Medium | Postorder; first node where both sides return non-null |
| 543 | [Diameter of Binary Tree](./543_Diameter_of_Binary_Tree.cpp) | 🟢 Easy | At each node: `leftHeight + rightHeight`; track global max |
| 572 | [Subtree of Another Tree](./572_Subtree_of_Another_Tree.cpp) | 🟢 Easy | Traverse root; at matching values run full equality check |
| 1448 | [Count Good Nodes in Binary Tree](./1448_Count_Good_Nodes_in_Binary_Tree.cpp) | 🟡 Medium | DFS carrying `maxSoFar` on path; node is good if ≥ max |

### BFS Problems

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 102 | [Binary Tree Level Order Traversal](./102_Binary_Tree_Level_Order_Traversal.cpp) | 🟡 Medium | Queue + snapshot `levelSize` each iteration |
| 199 | [Binary Tree Right Side View](./199_Binary_Tree_Right_Side_View.cpp) | 🟡 Medium | BFS; record last node of each level |

### String Manipulation (Tree-Adjacent)

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 151 | [Reverse Words in a String](./151_Reverse_Words_in_a_String.cpp) | 🟡 Medium | Reverse whole string, then reverse each word |
| 1910 | [Remove All Occurrences of a Substring](./1910_Remove_All_Occurrences_of_a_Substring.cpp) | 🟡 Medium | Repeatedly `find + erase` until no occurrence remains |
| 58 | [Length of Last Word](./58_Length_of_Last_Word.cpp) | 🟢 Easy | Reverse scan: skip trailing spaces, count word characters |

---

## ⛰️ Heap / Priority Queue

A max-heap or min-heap gives O(log n) insert/extract and O(1) peek — ideal for top-K problems and greedy scheduling.

| # | Problem | Difficulty | Key Idea |
|---|---|---|---|
| 215 | [Kth Largest Element in Array](./215_Kth_Largest_Element_in_an_Array.cpp) | 🟡 Medium | Min-heap of size k; top = kth largest |
| 239 | [Sliding Window Maximum](./239_Sliding_Window_Maximum.cpp) | 🔴 Hard | Max-heap with index; lazily remove out-of-window elements |
| 621 | [Task Scheduler](./621_Task_Scheduler.cpp) | 🟡 Medium | Max-heap; schedule up to `n+1` tasks per cycle greedily |
| 703 | [Kth Largest Element in a Stream](./703_Kth_Largest_Element_in_a_Stream.cpp) | 🟢 Easy | Min-heap of size k maintained on every `add()` call |
| 973 | [K Closest Points to Origin](./973_K_Closest_Points_to_Origin.cpp) | 🟡 Medium | Max-heap of size k by squared distance |
| 1046 | [Last Stone Weight](./1046_Last_Stone_Weight.cpp) | 🟢 Easy | Max-heap; extract two heaviest, push difference if unequal |

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

The repository is actively growing! Here are the upcoming sections:

### 🌐 Graphs
- BFS / DFS on graphs
- Union-Find / Disjoint Set
- Topological Sort
- Shortest Path (Dijkstra, BFS)

### 💡 Dynamic Programming
- 1D DP (Fibonacci variants, House Robber, Climbing Stairs)
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

| Pattern | Core Trick | Problems |
|---|---|---|
| Two Pointers | Two indices moving toward each other or at different speeds | 3Sum, Container With Most Water, Valid Palindrome |
| Sliding Window (Fixed) | Reuse previous sum; add new, remove old element | Max Vowels, Max Average Subarray |
| Sliding Window (Variable) | Shrink when constraint violated | Longest Substring No Repeat, Fruit Into Baskets |
| Binary Search | Eliminate half search space per step | All BS problems, Koko, Peak Index |
| HashMap | O(1) lookup for complement/frequency | Two Sum, Group Anagrams, Subarray Sum |
| Monotonic Stack | Stack kept in increasing/decreasing order | Daily Temperatures, Next Greater Element |
| Fast & Slow Pointers | Two speeds to find middle or detect cycle | Linked List Cycle, Middle of List |
| Prefix Sum | `prefix[j] - prefix[i]` gives range sum | Subarray Sum Equals K, Running Sum |
| Heap (Top-K) | Keep k best elements using opposite heap | Kth Largest, K Closest Points |
| Backtracking | Explore + undo choices recursively | Subsets, Permutations |
| Tree DFS | Postorder/preorder recursion carrying state | Diameter, LCA, Count Good Nodes |
| Tree BFS | Level-by-level queue traversal | Level Order, Right Side View |

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

Feel free to open an issue or pull request if you spot a bug, have a cleaner approach, or want to suggest a new problem to add.

---

*Happy coding! Consistency beats intensity — one problem a day keeps the FAANG away. 🚀*
