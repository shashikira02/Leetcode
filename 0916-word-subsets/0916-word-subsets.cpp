class Solution {
public:
        vector<int> get_frequency(string s)
    {
        vector<int> temp(26,0);
 
        for(int i=0;i<s.length();i++)
            temp[s[i]-'a']++;
 
        return temp;
    }   
 
    vector<string> wordSubsets(vector<string>& A, vector<string>& B)
    {
        int n = B.size();
        vector<string> ans;
 
        vector<int> countMax(26,0);
 
        for(int i=0;i<n;i++)
        {
            vector<int> temp = get_frequency(B[i]);
 
            for(int j=0;j<26;j++)
            {
                countMax[j] = max(countMax[j],temp[j]);
            }
        }
 
        for(int i=0;i<A.size();i++)
        {
            vector<int> temp = get_frequency(A[i]);
 
            for(int k=0;k<26;k++)
            {
                if(temp[k]<countMax[k])
                    goto h;
            }
 
            ans.push_back(A[i]);
            h:;
        }
 
        return ans;
    }
    
};