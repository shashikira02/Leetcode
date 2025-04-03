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

class BSTIterator {
    stack<TreeNode*> st;
    //reverse = true => before
    //reverse = false => next
    bool reverse ;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode*  temp = st.top();
        st.pop();
        if(!reverse)pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(TreeNode* node){// push all the left nodes in stack
        while(node!=nullptr ){
            st.push(node);
            if(reverse == true)node = node->right;
            else {
                node = node->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;

        BSTIterator l(root, false); // next
        BSTIterator r(root, true); // before
    
        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j == k)return true;
            else if(i+j < k)i = l.next();
            else j = r.next();
        }

        return false;
    }
};