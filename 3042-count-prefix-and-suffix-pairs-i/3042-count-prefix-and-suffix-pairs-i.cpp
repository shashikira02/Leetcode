class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        int n, m;
        for(int i = 0; i < words.size(); i++){
            n = words[i].size();
            for(int j = i + 1; j < words.size(); j++){
                m = words[j].size();
                if(m >= n && words[j].substr(0, n) == words[i] && words[j].substr(m - n) == words[i]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};