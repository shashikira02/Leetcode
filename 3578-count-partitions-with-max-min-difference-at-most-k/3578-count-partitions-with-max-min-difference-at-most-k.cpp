class Solution {
public:
    const unsigned int MOD = 1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n+1 , 0);
        vector<int>prefixSum(n+1 , 0);
        dp[0]=1;
        prefixSum[0]=1;

        multiset<int> st;

        for(int l =0, r=1; r<=n;r++){
            st.insert(nums[r-1]);

            while(*st.rbegin() - *st.begin() >k ){
                st.erase(st.find(nums[l]));
                l++;
            }

            int prev = (l>0) ? prefixSum[l-1]:0;
            dp[r] = (prefixSum[r-1] -prev + MOD)%MOD;
            prefixSum[r] = (prefixSum[r-1]+dp[r])%MOD;
        }

        return dp[n];
    }
};