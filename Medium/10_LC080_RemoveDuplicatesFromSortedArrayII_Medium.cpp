// LeetCode 80 - Remove Duplicates from Sorted Array II
// Question: Given a sorted array, remove duplicates in-place so each value
// appears at most twice. Return the number of kept elements.
// Approach: Write a value only when fewer than two values are kept, or it
// differs from the value two positions behind.
// Time: O(n) | Space: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int value : nums) {
            if (k < 2 || value != nums[k - 2]) {
                nums[k] = value;
                ++k;
            }
        }
        return k;
    }
};
