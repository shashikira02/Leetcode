class Solution {
public:
    set<string> res;
    map<int,int>flag;
    string s;

    void solve(string tiles){
        for(int i =0;i<tiles.size();i++){
            if(flag[i] != 1){
                s.push_back(tiles[i]);
                flag[i]=1;
                res.insert(s);
                solve(tiles);
                flag[i] =0;
                s.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        solve(tiles);

        return res.size();
    }
};