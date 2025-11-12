class Solution {
    int findMaxi(vector<string>& strs, int m, int n, int ind) {
        if (ind == strs.size())
            return 0;

        int zeros = count(strs[ind].begin(), strs[ind].end(), '0');
        int ones = strs[ind].size() - zeros;

        if (m >= zeros && n >= ones) {
            return max(1 + findMaxi(strs, m - zeros, n - ones, ind + 1),
                       findMaxi(strs, m, n, ind + 1));
        }

        return findMaxi(strs,m,n, ind+1);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return findMaxi(strs, m, n, 0);
    }
};