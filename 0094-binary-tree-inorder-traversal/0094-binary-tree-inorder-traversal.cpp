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
    void dfs(vector<int>&ans , TreeNode* root){
        if(root == nullptr)return;

        dfs(ans, root->left);
        ans.push_back(root->val);
        dfs(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        dfs(ans, root);

        return ans;
    }
};