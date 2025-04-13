class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return ""; // Handle empty input

        sort(strs.begin(), strs.end()); // Sort the strings lexicographically
        string first = strs[0], last = strs[n - 1]; // First and last strings after sorting
        string prefix = "";

        for (int i = 0; i < first.size() && i < last.size(); i++) {
            if (first[i] != last[i]) break; // Stop at the first mismatch
            prefix += first[i]; // Append matching characters to the prefix
        }

        return prefix; // Return the longest common prefix
    }
};
