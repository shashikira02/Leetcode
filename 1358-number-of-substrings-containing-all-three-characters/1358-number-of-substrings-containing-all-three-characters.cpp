class Solution {
public:
    int numberOfSubstrings(string s) {
        int count =0;
        int ls[3] ={-1,-1,-1};
        for(int i =0;i<s.size();i++){
            ls[s[i]-'a'] =i;

            count += 1+ min(min(ls[0],ls[1]),ls[2]);
        }
        return count;
    }
};