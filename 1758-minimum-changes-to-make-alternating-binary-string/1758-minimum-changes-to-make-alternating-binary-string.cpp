class Solution {
public:
    int minOperations(string s) {
        int zero = 0, one = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '1') {
                    zero++;
                } 
            } else {
                if (s[i] == '0') {
                    zero++;
                }
            }
        }
        return min(int(s.size())-zero, zero);
    }
};