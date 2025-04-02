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
    int maxDepth(TreeNode* root) { 
        if (root == nullptr) return 0; 
        int left = maxDepth(root->left); 
        int right = maxDepth(root->right); 
        return 1 + max(left, right); 
    } 

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = maxDepth(root->left);  // Depth of left subtree
        int right = maxDepth(root->right); // Depth of right subtree

        // Diameter passing through the current node
        int currDiameter = left + right;

        // Diameter of left and right subtrees
        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);

        // Maximum diameter across the tree
        return max(currDiameter, max(leftDia, rightDia));
    }
};
