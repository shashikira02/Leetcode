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
    int mod = 1e9 + 7;
    long long totsum = 0, result = 0;

    void Totsum(TreeNode* root) {
        if (!root) return;
        totsum += root->val;
        Totsum(root->left);
        Totsum(root->right);
    }

    int subtreesum(TreeNode* root) {
        if (!root) return 0;
        // Left and right subtreesum
        int leftsum = subtreesum(root->left);
        int rightsum = subtreesum(root->right);

        // Finding max subproduct
        result = max({result, (totsum - leftsum) * leftsum, (totsum - rightsum) * rightsum});

        return leftsum + rightsum + root->val;
    }

    int maxProduct(TreeNode* root) {
        totsum = 0;
        result = 0;
        Totsum(root);
        subtreesum(root);
        return result % mod;
    }
};
