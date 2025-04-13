class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        string s1 = "";

        for(int i =n-1;i>=0;i--){
            s1 += s[i];
        }

        vector<int>curr(n+1, 0), prev(n+1, 0);

        for(int i =1;i<=n;i++){
            for(int j =1; j<=n;j++){
                if(s[i-1] == s1[j-1]) curr[j] = 1+ prev[j-1];
                else curr[j] = max(prev[j] , curr[j-1]);
            }
            prev = curr;
        }

        int palLen= prev[n];
        int ans = n- palLen;
        return ans;
    }
};