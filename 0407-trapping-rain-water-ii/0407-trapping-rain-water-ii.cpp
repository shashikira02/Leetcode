class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
    int row = h.size();
    int col = h[0].size();
    if(row<=2 or col<=2)    return 0;    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<int>> vis(row, vector(col,0)) ;
    
    for(int i = 0;i<row; i++){
        for(int j = 0; j<col; j++){
            if(i==0 or j==0 or i ==row-1 or j== col-1){
                pq.push({h[i][j], {i, j}});
                vis[i][j] = 1;
            }
        }
    }
    vector<pair<int, int>> dir = {{-1, 0}, {1,0}, {0, -1}, {0, 1}};
    int ans = 0;
    while(!pq.empty()){
        int x = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        for(int i = 0; i<dir.size(); i++){
            int nr = dir[i].first + r;
            int nc = dir[i].second +c;            
            if(nr>=0 and nc>=0 and nr<row and nc<col and vis[nr][nc]==0){
                ans += max(0, x - h[nr][nc]);
                vis[nr][nc]=1;
                pq.push({max(h[nr][nc], x), {nr, nc}});
            }
        }
        
    }
    return ans;
}
};