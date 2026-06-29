/*
Problem 415. Add Strings

Problem Statement:

Given two non-negative integers num1 and num2 represented as strings,
return their sum as a string.

You must solve the problem without converting the entire strings
into integers or using any built-in big integer library.

--------------------------------------------------

Intuition:

Since the numbers are stored as strings, we cannot directly perform
integer addition.

The easiest approach is to simulate the same process we use while
adding numbers by hand:

- Start from the last digit of both numbers.
- Add corresponding digits along with any carry from the previous step.
- Store the current digit of the answer.
- Continue until all digits and the carry have been processed.

Since we generate the answer from right to left, we reverse it at the end.

--------------------------------------------------

Key Idea:

Step 1: Use two pointers starting from the end of both strings.
Step 2: Add the current digits and the carry.
Step 3: Store the last digit of the sum.
Step 4: Update the carry.
Step 5: Continue until both strings and the carry are exhausted.
Step 6: Reverse the answer and return it.

--------------------------------------------------

Approach:

1. Initialize two pointers:
   - i at the last index of num1.
   - j at the last index of num2.
2. Initialize carry = 0 and an empty answer string.
3. While either string still has digits or carry exists:
   - Start the current sum with carry.
   - If i is valid, add num1[i].
   - If j is valid, add num2[j].
   - Append (sum % 10) to the answer.
   - Update carry = sum / 10.
4. Reverse the answer string.
5. Return the final result.

--------------------------------------------------

Example:

Input:
num1 = "456"
num2 = "77"

Process:

6 + 7 = 13
Digit = 3
Carry = 1

5 + 7 + 1 = 13
Digit = 3
Carry = 1

4 + 0 + 1 = 5
Digit = 5
Carry = 0

Answer built:
"335"

Reverse:
"533"

Output:
"533"

--------------------------------------------------

Counter Example:

Input:
num1 = "999"
num2 = "1"

Process:

9 + 1 = 10
Digit = 0
Carry = 1

9 + 0 + 1 = 10
Digit = 0
Carry = 1

9 + 0 + 1 = 10
Digit = 0
Carry = 1

Carry remains:
1

Answer built:
"0001"

Reverse:
"1000"

Output:
"1000"

--------------------------------------------------

Why This Works:

The algorithm performs digit-by-digit addition exactly like manual
addition. At every step, the carry is propagated to the next higher
place value, ensuring the final result is correct.

Since digits are processed from least significant to most significant,
the answer is built in reverse order and reversed once at the end.

--------------------------------------------------

Time Complexity: O(max(n, m))

Each digit of both strings is processed exactly once.

--------------------------------------------------

Space Complexity: O(max(n, m))

The answer string stores the resulting sum.

--------------------------------------------------

Pattern Used:
Two Pointers / String Simulation

Key Learning:

1. String problems often simulate the corresponding arithmetic operation.
2. Two pointers starting from the end make digit-by-digit processing easy.
3. Always continue while carry exists, even if both strings have been fully processed.
4. When constructing an answer from least significant to most significant digit,
   remember to reverse it before returning.
*/

class Solution {
public:

    string addStrings(string num1, string num2) {

        int i = num1.size() - 1;
        int j = num2.size() - 1;

        string ans = "";
        int carry = 0;

        while(i >= 0 || j >= 0 || carry)
        {
            int sum = carry;

            if(i >= 0)
            {
                sum += num1[i] - '0';
                i--;
            }

            if(j >= 0)
            {
                sum += num2[j] - '0';
                j--;
            }

            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
