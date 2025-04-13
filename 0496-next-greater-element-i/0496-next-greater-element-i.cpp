class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp; // Map to store the next greater element for nums2 elements
        stack<int> st;              // Stack to keep track of elements while traversing nums2

        // Iterate nums2 from right to left to find next greater element for each number
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // Remove elements from the stack that are smaller or equal to the current element
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop(); // Pop smaller elements as they cannot be the next greater
            }

            // If the stack is not empty, the top of the stack is the next greater element
            if (!st.empty()) {
                mpp[nums2[i]] = st.top(); // Map current element to its next greater element
            } else {
                mpp[nums2[i]] = -1; // No greater element exists, so map it to -1
            }

            // Push the current element onto the stack to serve as a potential next greater
            st.push(nums2[i]);
        }

        vector<int> ans; // Vector to store results for nums1

        // For each number in nums1, get its next greater element from the map
        for (int num : nums1) {
            ans.push_back(mpp[num]); // Lookup next greater element in the map
        }

        return ans; // Return the result vector containing the next greater elements for nums1
    }
};
