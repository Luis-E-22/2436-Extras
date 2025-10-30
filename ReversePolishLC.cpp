class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     stack<int> stk;

        // Iterate through each token
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Operator: Pop the top two elements
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();

                // Apply the operator
                if (token == "+") {
                    stk.push(a + b);
                } else if (token == "-") {
                    stk.push(a - b);
                } else if (token == "*") {
                    stk.push(a * b);
                } else if (token == "/") {
                    // Integer division with truncation towards zero
                    stk.push(a / b);
                }
            } else {
                // Operand: Convert the string to an integer and push onto the stack
                stk.push(stoi(token));
            }
        }

        // The result will be the only element left in the stack
        return stk.top();   
    }
};

