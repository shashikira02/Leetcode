class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0; // Pointers for traversing both strings
        int len1 = version1.size(), len2 = version2.size();

        while (i < len1 || j < len2) {
            int n1 = 0, n2 = 0; // Initialize numbers for the current segment

            // Extract the number from version1 until a '.' or the end of the string
            while (i < len1 && version1[i] != '.') {
                n1 = n1 * 10 + (version1[i] - '0');
                i++;
            }

            // Extract the number from version2 until a '.' or the end of the string
            while (j < len2 && version2[j] != '.') {
                n2 = n2 * 10 + (version2[j] - '0');
                j++;
            }

            // Compare the two numbers
            if (n1 < n2) return -1;
            else if (n1 > n2) return 1;

            // Move to the next segment (skip the '.')
            i++;
            j++;
        }

        return 0; // Both versions are equal
    }
};
