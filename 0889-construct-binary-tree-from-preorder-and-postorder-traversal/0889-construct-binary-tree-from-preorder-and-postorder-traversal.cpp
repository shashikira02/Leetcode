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
    
// Here start & end belongs to post-order vector.
// currIndex belongs to pre-order vector.
    int currIndex = 0;
    TreeNode* helperDFS(vector<int>& pre,vector<int>& post,int start,int end,unordered_map<int,int>& index)
    {
        if(start > end)
            return NULL;
        
        TreeNode* newNode = new TreeNode(pre[currIndex++]);
        if(start == end)
        {
            return newNode;
        }

        int post_index = index[pre[currIndex]];

        newNode->left = helperDFS(pre,post,start,post_index,index);
        newNode->right = helperDFS(pre,post,post_index+1,end-1,index);

        return newNode;

    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        unordered_map<int,int> index;
        for(int i=0;i<postorder.size();i++)
        {
            index[postorder[i]] = i;
        }

        return helperDFS(preorder,postorder,0,postorder.size()-1,index);

    }
};