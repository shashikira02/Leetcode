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
    unordered_map<TreeNode* , int> dp;

    int rob(TreeNode* root) {
        if(!root)return 0;
        
        if(dp.find(root)!= dp.end())return dp[root];

        int curr = root->val;

        if(root->left){
            curr += rob(root->left->left);
            curr += rob(root->left->right);
        }
        if(root->right){
            curr += rob(root->right->left);
            curr += rob(root->right->right);
        }

        int skip = rob(root->right) + rob(root->left);

        return dp[root] = max(skip, curr);

    }
};