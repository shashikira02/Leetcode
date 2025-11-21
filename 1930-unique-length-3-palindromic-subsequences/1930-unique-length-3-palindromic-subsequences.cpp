class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> st;
        int n = s.length();

        for (char c = 'a'; c <= 'z'; c++) {
            int first = -1, last = -1;

            for (int i = 0; i < n; i++) {
                if (s[i] == c) {
                    if (first == -1)
                        first = i;
                    last = i;
                }
            }

            if (first != -1 && last > first) {
                unordered_set<char> words;
                for (int i = first + 1; i < last; i++) {
                    words.insert(s[i]);
                }

                for (char ch : words) {
                    string palindrome = "";
                    palindrome += c;
                    palindrome += ch;
                    palindrome += c;
                    st.insert(palindrome);
                }
            }
        }
        return st.size();
    }
};