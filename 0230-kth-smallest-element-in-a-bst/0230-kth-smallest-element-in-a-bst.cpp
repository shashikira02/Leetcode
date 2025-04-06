class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> st;
        TreeNode* curr = root;
        int count = 0; // Keep track of the elements processed

        // Iterative in-order traversal
        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr); // Push all left nodes onto the stack
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            // Process the current node
            count++;
            if (count == k) return curr->val;

            // Move to the right subtree
            curr = curr->right;
        }

        return -1; // if k is out of bounds
    }
};
