// LeetCode 84 - Largest Rectangle in Histogram
// Question: Given bar heights in a histogram (each bar has width 1), return
// the largest rectangular area that can be formed.
// Approach: Monotonic increasing stack of indices; calculate areas when a
// shorter bar ends the width of taller bars.
// Time: O(n) | Space: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indices;
        int n = (int)heights.size();
        int best = 0;

        for (int i = 0; i <= n; ++i) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!indices.empty() &&
                   heights[indices.top()] > currentHeight) {
                int height = heights[indices.top()];
                indices.pop();

                int width = indices.empty()
                    ? i
                    : i - indices.top() - 1;

                best = max(best, height * width);
            }

            if (i < n) indices.push(i);
        }
        return best;
    }
};
