class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mindiff = INT_MAX;

        for(int i=0;i<n-1;i++){
            int diff = arr[i+1]-arr[i];
            mindiff = min(mindiff,diff);
        }

        vector<vector<int>> res;

        for(int i=0;i<n-1;i++){
            int diff = arr[i+1]-arr[i];
            if(mindiff == diff)res.push_back({arr[i],arr[i+1]});
        }

        return res;
    }
};