// LeetCode 977 - Squares of a Sorted Array
// Question: Return an array containing the squares of each number, sorted
// in non-decreasing order. The input array is already sorted.
// Approach: Compare absolute values at both ends using two pointers.
// Time: O(n) | Space: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> answer(n);
        int left = 0, right = n - 1;

        for (int i = n - 1; i >= 0; --i) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                answer[i] = leftSquare;
                ++left;
            } else {
                answer[i] = rightSquare;
                --right;
            }
        }
        return answer;
    }
};
