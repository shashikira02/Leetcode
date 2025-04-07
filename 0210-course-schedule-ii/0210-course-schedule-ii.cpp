class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, stack<int>& st, vector<vector<int>>& adj){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, vis, pathVis, st, adj)){
                    return true;
                }
            }
            else if(pathVis[adjNode])return true;
        }

        pathVis[node] =0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
               if( dfs(i, vis, pathVis, st,  adj)){
                return {};
               }
            }
        }
        
        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};