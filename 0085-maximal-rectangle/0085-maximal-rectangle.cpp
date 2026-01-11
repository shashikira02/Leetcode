class Solution {
public:
    vector<int> NSR(vector<int>& height) {
        stack<int> st;
        int n = height.size();

        vector<int> right(n);
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty())
                right[i] = n;
            else {
                while (!st.empty() && height[st.top()] >= height[i])
                    st.pop();

                if (st.empty())
                    right[i] = n;
                else
                    right[i] = st.top();
            }
            st.push(i);
        }

        return right;
    }

    vector<int> NSL(vector<int>& height) {
        stack<int> st;
        int n = height.size();

        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            if (st.empty())
                left[i] = -1;
            else {
                while (!st.empty() && height[st.top()] >= height[i])
                    st.pop();

                if (st.empty())
                    left[i] = -1;
                else
                    left[i] = st.top();
            }
            st.push(i);
        }

        return left;
    }

    int findMaxArea(vector<int>& height) {

        // w - nsr[i] - nsl[i]-1;
        // height - height

        vector<int>nsr = NSR(height);
        vector<int>nsl = NSL(height);

        int n = height.size();

        vector<int>width(n);
        for(int i =0;i<n;i++){
            width[i] = nsr[i] - nsl[i]-1;
        }
        int maxArea = 0;

        for(int i =0;i<n;i++){
            maxArea = max(maxArea, width[i]*height[i]);
        }

        return maxArea;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m);

        for (int i = 0; i < m; i++)
            height[i] = (matrix[0][i] == '1') ? 1 : 0;

        int maxArea = findMaxArea(height);

        for (int r = 1; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (matrix[r][c] == '0')
                    height[c] = 0;
                else
                    height[c] += 1;
            }
            maxArea = max(maxArea, findMaxArea(height));
        }

        return maxArea;
    }
};