class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(),m = t.size();
        int freq[26] = {0};
        if(n !=m) return false;
        for(int i =0;i<n;i++){
            freq[s[i] -'a'] ++;
        }
        for(int j =0;j<n;j++){
            freq[t[j] -'a'] --;
        }
        for(int k =0;k<26;k++){
            if(freq[k] != 0) return false;
        }

        return true;
    }
};