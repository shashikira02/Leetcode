class Solution {
public:
    int maxDifference(string s) {
        vector<int> mp(26);
        int maxiOdd =0, miniEven = s.size();
        for(auto c: s)mp[c -'a']++;

        for(int i =0;i<26;i++){
            if(mp[i]%2 !=0)maxiOdd = max(maxiOdd, mp[i]);
            if(mp[i]%2 ==0 && mp[i] > 0)miniEven = min(miniEven, mp[i]);
        }
        return maxiOdd-miniEven;
    }
};