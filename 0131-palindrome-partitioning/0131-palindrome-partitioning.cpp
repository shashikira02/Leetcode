class Solution {
public:
    bool isPalindrome(string s, int start,int end){
        while(start <= end){
            if(s[start++] != s[end--])return false;
        }
        return true;
    }
    void palPartitioning(int ind,string s,vector<string>&substr ,vector<vector<string>>&ans){
        if(ind == s.size()){
            ans.push_back(substr);
            return;
        }
        for(int i = ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                substr.push_back(s.substr(ind,i-ind+1));
                palPartitioning(i+1,s,substr,ans);
                substr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> substr;//individual substrs
        palPartitioning(0,s,substr,ans);
        return ans;
    }
};