// LeetCode 1047 - Remove All Adjacent Duplicates in String
// Question: Repeatedly remove pairs of adjacent equal characters and return
// the resulting string.
// Approach: Use the output string as a stack.
// Time: O(n) | Space: O(n)

class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for (char ch : s) {
            if (!result.empty() && result.back() == ch) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }
};
