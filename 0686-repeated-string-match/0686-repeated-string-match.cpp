class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        // Repeat until repeated string is at least as long as b
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        // Check if b is a substring
        if (repeated.find(b) != string::npos) return count;

        // Add one more repetition to handle overlaps
        repeated += a;
        if (repeated.find(b) != string::npos) return count + 1;

        // If still not found
        return -1;
    }
};
