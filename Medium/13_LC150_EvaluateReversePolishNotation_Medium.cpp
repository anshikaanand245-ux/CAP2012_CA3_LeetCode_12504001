// LeetCode 150 - Evaluate Reverse Polish Notation
// Question: Evaluate an arithmetic expression written in Reverse Polish
// Notation. Division between integers truncates toward zero.
// Approach: Push numbers; when an operator appears, pop the right and left
// operands, calculate, and push the result.
// Time: O(n) | Space: O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {
                int right = values.top(); values.pop();
                int left = values.top(); values.pop();

                if (token == "+") values.push(left + right);
                else if (token == "-") values.push(left - right);
                else if (token == "*") values.push(left * right);
                else values.push(left / right);
            } else {
                values.push(stoi(token));
            }
        }
        return values.top();
    }
};
