class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store nodes grouped by their vertical level and sorted by depth/y
        map<int, map<int, vector<int>>> nodes;
        
        // Queue for BFS traversal: stores nodes with their vertical and horizontal coordinates
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            
            TreeNode* node = p.first;
            int x = p.second.first;  // Vertical level
            int y = p.second.second; // Depth
            
            // Group node values by vertical (x) and depth (y)
            nodes[x][y].push_back(node->val);
            
            if (node->left) todo.push({node->left, {x - 1, y + 1}});
            if (node->right) todo.push({node->right, {x + 1, y + 1}});
        }
        
        vector<vector<int>> ans;
        
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                // Sort values within the same depth/y to ensure ascending order
                sort(q.second.begin(), q.second.end());
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};
