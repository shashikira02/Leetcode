/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* tree(vector<int>& preorder, int& preIndex, int inStart, int inEnd, unordered_map<int, int>& mp) {
        // Base case: if inStart > inEnd, no valid subtree exists
        if (inStart > inEnd) return NULL;

        // Create the root node using the current preorder index
        TreeNode* root = new TreeNode(preorder[preIndex]);
        int inRoot = mp[root->val]; // Find index in inorder traversal

        preIndex++; // Move to the next root in preorder

        // Build left subtree
        root->left = tree(preorder, preIndex, inStart, inRoot - 1, mp);

        // Build right subtree
        root->right = tree(preorder, preIndex, inRoot + 1, inEnd, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i; // Store value-to-index mapping for inorder traversal
        }

        int preIndex = 0; // Start with the first element in preorder
        return tree(preorder, preIndex, 0, inorder.size() - 1, mp);
    }
};
