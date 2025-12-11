class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> rMin(n+1, n+1);
        vector<int> rMax(n+1, 0);
        vector<int> cMin(n+1, n+1);
        vector<int> cMax(n+1, 0);

        for(auto &bui : buildings){
            int i = bui[0], j = bui[1];
            rMax[j] = max(rMax[j], i);
            rMin[j] = min(rMin[j], i);
            cMax[i] = max(cMax[i], j);
            cMin[i] = min(cMin[i], j);
        }
        
        int ans =0;

        for(auto &bui: buildings){
            int i = bui[0], j =bui[1];
            if(i > rMin[j] && i < rMax[j] && j>cMin[i] && j<cMax[i])ans++;
        }

        return ans;
    }
};