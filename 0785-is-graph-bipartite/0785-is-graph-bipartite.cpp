class Solution {
public:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& adj) {
        color[node] = col;
        for (auto adjNode : adj[node]) {
            if (color[adjNode] == -1) {
                if(dfs(adjNode, !col, color, adj) == false) return false;
            } else if (color[adjNode] == col)
                return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, graph) == false)
                    return false;
            }
        }

        return true;
    }
};