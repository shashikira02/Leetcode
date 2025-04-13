class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int len = 0;
        int n = s.size();
        for(int i =0;i<n;i++){
            //odd len
    
                int l =i, r= i;
                while(l>=0 && r < n && s[l] == s[r]){
                    if((r-l+1) > len){
                        ans = s.substr(l,r-l+1);
                        len = r-l+1;
                    }
                    l--;
                    r++;
                }
            
                //even len
                l =i, r= i+1;
                while(l>=0 && r < n && s[l] == s[r]){
                    if((r-l+1) > len){
                        ans = s.substr(l,r-l+1);
                        len = r-l+1;
                    }
                    l--;
                    r++;
                }
            
        }
        return ans;
    }
};