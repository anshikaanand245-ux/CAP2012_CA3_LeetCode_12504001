// LeetCode 2520 - Count the Digits That Divide a Number
// Question: Given a positive integer num, count its digits that divide num evenly.
// Approach: Extract each digit with % 10 and test num % digit.
// Time: O(log n) | Space: O(1)

class Solution {
public:
    int countDigits(int num) {
        int original = num;
        int count = 0;

        while (num > 0) {
            int digit = num % 10;
            if (digit != 0 && original % digit == 0) {
                ++count;
            }
            num /= 10;
        }
        return count;
    }
};
