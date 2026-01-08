class Solution {
public:
    int maxi = -1e9;
    int func(int i, int j, vector<int>& a, vector<int>& b, vector<vector<int>>& dp){
        if(i == a.size() || j == b.size())return maxi;

        if(dp[i][j] != INT_MIN)return dp[i][j];
        int take = a[i]*b[j];
        int cont = a[i]* b[j] + func(i+1, j+1, a, b, dp);
        int skipA = func(i+1, j, a, b, dp);
        int skipB = func(i, j+1, a, b, dp);

        return dp[i][j] = max({take, cont , skipA, skipB});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        vector<vector<int>>dp(n, vector<int>(m, INT_MIN));

        return func(0,0,nums1, nums2, dp);

    }
};