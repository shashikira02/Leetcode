class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); // Total number of bars in histogram
        stack<int> st;          // Stack to store indices of histogram bars
        int maxArea = 0;        // Variable to track the maximum area

        // Iterate through all bars and an extra index for final computation
        for (int i = 0; i <= n; i++) {
            // Process bars when current height is smaller or at the end
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int length = heights[st.top()]; // Height of top bar in stack
                st.pop(); // Remove top bar after using it for computation
                int width; 
                // Compute width based on stack state
                if (st.empty()) width = i; // Width spans from 0 to current index
                else width = i - st.top() - 1; // Width spans between current and stack top

                // Update maxArea if current rectangle area is larger
                maxArea = max(maxArea, width * length);
            }
            st.push(i); // Push current index into stack
        }

        return maxArea; // Return the largest rectangle area
    }
};
