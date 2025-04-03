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
    TreeNode* bTree(vector<int>&nums, int start, int end){
        if(start>end)return NULL;

        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = bTree(nums,start, mid-1);
        root->right = bTree(nums,mid+1, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bTree(nums, 0,nums.size()-1);
    }
};