class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size(), col = heightMap[0].size();

        if (row <= 2 or col <= 2)
            return 0;

        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> vis(row, vector(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    pq.push({heightMap[i][j], {i,j}});
                    vis[i][j] =1;
                }
            }
        }

        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int ans =0;

        while(!pq.empty()){
            int h = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            for(int i =0;i<4;i++){
                int newR = dir[i].first+r;
                int newC = dir[i].second+c;

                if(newR >=0 && newC >=0 && newR<row && newC<col && vis[newR][newC]==0){
                    ans += max(0,h-heightMap[newR][newC]);
                    vis[newR][newC]=1;
                    pq.push({max(heightMap[newR][newC], h), {newR, newC}});
                }
            }
        }
        return ans;
    }
};