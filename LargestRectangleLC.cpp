class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      stack<int> stk;  // Stack to store indices of bars
        int maxArea = 0; // To store the maximum area
        int n = heights.size();
        
        for (int i = 0; i < n; ++i) {
            // While the current height is less than the height at the top of the stack
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];  // Height of the rectangle
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;  // Calculate the width
                maxArea = max(maxArea, h * width);  // Update the maximum area
            }
            stk.push(i);  // Push the current index to the stack
        }
        
        // Now, process any remaining bars in the stack
        while (!stk.empty()) {
            int h = heights[stk.top()];  // Height of the rectangle
            stk.pop();
            int width = stk.empty() ? n : n - stk.top() - 1;  // Calculate the width
            maxArea = max(maxArea, h * width);  // Update the maximum area
        }
        
        return maxArea;  
    }
};