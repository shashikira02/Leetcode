class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans; // Stores the maximums of all sliding windows
        deque<int> dq;   // Deque to store indices of potential maximums

        for (int i = 0; i < nums.size(); i++) {
            // Remove index that are out of the current window
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();

            // Remove smaller elements as they cannot be maximum (indices)
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            // Add the current element's index to the deque
            dq.push_back(i);

            // Add the max of current window to the result when the window is valid
            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }

        return ans; // Return the result containing all window maximums
    }
};
