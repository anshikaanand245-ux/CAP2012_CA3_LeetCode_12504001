// LeetCode 70 - Climbing Stairs
// Question: You are climbing a staircase with n steps. You can climb either
// 1 or 2 steps at a time. Return the number of distinct ways to reach the top.
// Approach: Dynamic programming (keep the previous two answers).
// Time: O(n) | Space: O(1)

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int a = 1, b = 2;
        for (int i = 3; i <= n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
