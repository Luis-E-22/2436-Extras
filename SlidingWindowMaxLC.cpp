class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> result;
        deque<int> dq; // Deque to store indices of elements in the window
        
        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements from the front of the deque that are out of the current window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // Remove elements from the back of the deque that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // Add the current element's index to the deque
            dq.push_back(i);
            
            // The window is valid when we've processed at least 'k' elements
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;  
    }
};