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
    bool symmetric(TreeNode* leftTree,TreeNode* rightTree){
        if (!leftTree && !rightTree) return true;  
        if (!leftTree || !rightTree) return false;



        return (leftTree->val == rightTree->val)&&
                (symmetric(leftTree->left,rightTree->right)) && 
                (symmetric(leftTree->right, rightTree->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return symmetric(root->left, root->right);
    }
};