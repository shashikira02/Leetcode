class Solution {
public:
    bool bfs(int start, int V, vector<int>& color, vector<vector<int>>& adj ){
        queue<int>q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjNode: adj[node]){
                if(color[adjNode] == -1){
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                }
                else if(color[adjNode] == color[node])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);

        for(int i =0;i<n;i++){
            if(color[i] ==-1){
                if(bfs(i, n , color, graph) == false)return false;
            }
        }

        return true;
    }
};