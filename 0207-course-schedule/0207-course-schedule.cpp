class Solution {
public:
    bool check(int src, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj){
        vis[src] = 1;
        pathVis[src] =1;

        for(auto adjNode: adj[src]){
            if(!vis[adjNode]){
                if(check(adjNode, vis, pathVis, adj))return true;
            }
            else if(pathVis[adjNode])return true;
        }
        pathVis[src] =0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>>adj(v);

        for(auto& pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }

        vector<int> vis(v,0), pathVis(v,0);

        for(int i =0;i<v;i++){
            if(!vis[i]){
                if(check(i, vis, pathVis, adj))return false;
            }
        }

        return true;
    }
};