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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
    if (root == nullptr) {
            return nullptr;
        }
        int leftDepth = getDepth(root->left);  
        int rightDepth = getDepth(root->right);
        if (leftDepth == rightDepth) {
            return root;  
        } else {
            if(leftDepth > rightDepth){
                return lcaDeepestLeaves(root->left);
            } else {
                return lcaDeepestLeaves(root->right);
            }
        }
    }
    
    int getDepth (TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(getDepth(node->left), getDepth(node->right)); 
    }
};
