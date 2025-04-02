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
    int maxDepth(TreeNode* root, int& maxi) { 
        if(root == nullptr) return 0; 
        int left = maxDepth(root->left,maxi); 
        int right = maxDepth(root->right,maxi); 
        maxi = max(maxi, left+ right);
        return 1+ max(left, right); 
    } 

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;
        maxDepth(root, diameter);
        return diameter;
    }
};