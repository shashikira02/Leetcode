class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1"; // Return type should be a string
        
        string prev = countAndSay(n - 1); // Recursively get the previous sequence
        int count = 1; // Initialize count
        string ans = ""; // Initialize result string
        
        for (int i = 1; i < prev.size(); i++) { // Iterate through the string
            if (prev[i] != prev[i - 1]) { // When current char differs from previous char
                ans += to_string(count) + prev[i - 1]; // Append count and character
                count = 1; // Reset count
            } else {
                count += 1; // Increment count if characters are the same
            }
        }
        
        // Add the last group (for the last character sequence)
        ans += to_string(count) + prev[prev.size() - 1];
        
        return ans; // Return the result string
    }
};
