#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<set<int>> knows(m);

        for (int i = 0; i < m; i++) {
            for (int lan : languages[i]) knows[i].insert(lan);
        }
        
        vector<pair<int,int>> toTeach;

        for (auto& fr : friendships) {
            int u = fr[0] - 1; 
            int v = fr[1] - 1;
            bool share = false;
            auto& A = (knows[u].size() <= knows[v].size()) ? knows[u] : knows[v];
            auto& B = (knows[u].size() <= knows[v].size()) ? knows[v] : knows[u];
            for (int lang : A) {
                if (B.count(lang)) { 
                    share = true; 
                    break; 
                }
            }
            if (!share) toTeach.push_back({u, v});
        }

        if (toTeach.empty()) return 0;

        int best = m;
        for (int L = 1; L <= n; ++L) {
            int count = 0;
            set<int> added;
            for (const auto& p : toTeach) {
                int u = p.first, v = p.second;
                if (!knows[u].count(L) && added.insert(u).second) count++;
                if (!knows[v].count(L) && added.insert(v).second) count++;
            }
            best = min(best, count);
        }

        return best;
    }
};
