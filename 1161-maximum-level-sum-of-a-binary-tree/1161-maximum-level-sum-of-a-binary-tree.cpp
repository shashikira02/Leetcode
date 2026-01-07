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
    int maxLevelSum(TreeNode* root) {
        
        int ans =0;
        int maxSum = INT_MIN, level =0;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            level++;
            int currSum =0;
            
            int n = q.size();

            for(int i =0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                currSum += node->val;

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

            if(currSum > maxSum){
                maxSum = currSum;
                ans = level;
            }

        }
        return ans;
    }
};