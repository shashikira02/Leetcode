class Solution {
public:
    bool dfs(int node, vector<bool>& vis, vector<bool>& pathVis, stack<int>& st,
             vector<vector<int>>& adj) {
        vis[node] = true;
        pathVis[node] = true;

        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, vis, pathVis, st, adj))
                    return true;
            } else if (pathVis[adjNode]) {
                return true;
            }
        }

        st.push(node);
        pathVis[node] = false;

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);

        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                if (dfs(i, vis, pathVis, st, adj))
                    return {};
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};