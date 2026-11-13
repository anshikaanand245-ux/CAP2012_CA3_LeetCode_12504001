// LeetCode 35 - Search Insert Position
// Question: Given a sorted array of distinct integers and a target, return
// its index if found; otherwise return the index where it should be inserted.
// Approach: Binary search.
// Time: O(log n) | Space: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};
