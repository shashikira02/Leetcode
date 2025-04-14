class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Initialize base case for the first row (empty s1 -> s2)
        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i; // Base case for the first column (empty s2 -> s1)
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = prev[j - 1]; // Matching characters
                } else {
                    curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]}); // Non-matching characters
                }
            }
            prev = curr; // Update previous row
        }

        return prev[m]; // Return final result
    }
};
