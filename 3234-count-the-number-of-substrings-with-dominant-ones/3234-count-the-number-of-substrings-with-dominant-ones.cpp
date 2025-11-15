class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> nextZero(n + 1, n);

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')nextZero[i] = i;
            else nextZero[i] = nextZero[i + 1];
        }

        int res = 0;

        for (int l = 0; l < n; l++) {
           int firstZero = nextZero[l];
            if (firstZero > l) {
                res += (firstZero - l); 
            }
            int z = 1;
            int pz = firstZero; 
            while (pz < n && z * z <= n) {
                int nextP = (pz + 1 <= n ? nextZero[pz + 1] : n);
                int lowerJ = max(pz, l + z + z * z - 1);
                int upperJ = nextP - 1; 

                if (lowerJ <= upperJ) {
                    res += (upperJ - lowerJ + 1);
                }

                pz = nextP;
                z++;
            }
        }

        return res;
    }
};