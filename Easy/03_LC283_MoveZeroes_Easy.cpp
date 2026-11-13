// LeetCode 283 - Move Zeroes
// Question: Move all zeroes to the end of the array while keeping the order
// of non-zero elements unchanged. Do it in-place.
// Approach: Two pointers; place each non-zero value in the next open position.
// Time: O(n) | Space: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int next = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[next]);
                ++next;
            }
        }
    }
};
